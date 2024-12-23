#pragma once

/// \file

#include <Foundation/Containers/Map.h>
#include <Foundation/Strings/String.h>
#include <Foundation/Types/Variant.h>
#include <Foundation/Utilities/EnumerableClass.h>

/// \brief A class to broadcast and handle global (system-wide) events.
///
/// A global event is an event that will be sent to all instances of nsGlobalEvent (or rather their
/// respective handler functions), without the need to first register these event-handlers anywhere.
/// Thus they are very useful to notify sub-systems of certain important events, such as that some kind of
/// initialization will be done shortly, which means they can react by preparing properly.
/// For example the nsStartup-class will send certain events before doing startup and shutdown steps, which
/// allows code to free resources before a sub-system might be shut down.
/// nsGlobalEvent's should be used when there is a kind of event that should be propagated throughout the entire
/// engine, without knowledge which systems might want to know about it. These systems can then use an
/// nsGlobalEvent-instance to hook themselves into the global-event pipeline and react accordingly.
/// Global events should mostly be used for startup / configuration / shutdown procedures.
/// Also one should never assume any specific order of execution, all event handlers should be completely independent
/// from each other.
///
/// To create a global event handler, simply add this code inside a cpp file:
///
/// NS_ON_GLOBAL_EVENT(EventName)
/// {
///   ... do something ...
/// }
///
/// You can also use NS_ON_GLOBAL_EVENT_ONCE, if the handler should only be executed the first time the event is sent.
/// This is more efficient than filtering out duplicate events inside the event handler.
class NS_FOUNDATION_DLL nsGlobalEvent : public nsEnumerable<nsGlobalEvent>
{
  NS_DECLARE_ENUMERABLE_CLASS(nsGlobalEvent);

public:
  struct NS_FOUNDATION_DLL EventData
  {
    EventData();

    nsUInt32 m_uiNumTimesFired;
    nsUInt16 m_uiNumEventHandlersRegular;
    nsUInt16 m_uiNumEventHandlersOnce;
  };

  using EventMap = nsMap<nsString, EventData>;

public:
  /// \brief [internal] Use the macro NS_ON_GLOBAL_EVENT or NS_ON_GLOBAL_EVENT_ONCE to create an event handler.
  using NS_GLOBAL_EVENT_HANDLER = void (*)(const nsVariant&, const nsVariant&, const nsVariant&, const nsVariant&);

  /// \brief [internal] Use the macro NS_ON_GLOBAL_EVENT or NS_ON_GLOBAL_EVENT_ONCE to create an event handler.
  nsGlobalEvent(nsStringView sEventName, NS_GLOBAL_EVENT_HANDLER eventHandler, bool bOnlyOnce); // [tested]

  /// \brief This function will broadcast a system wide event to all event handlers that are registered to handle this specific type of event.
  ///
  /// The string specifies the event type, the parameters are optional and can be used to send additional event specific data.
  static void Broadcast(nsStringView sEventName, nsVariant param0 = nsVariant(), nsVariant param1 = nsVariant(), nsVariant param2 = nsVariant(),
    nsVariant param3 = nsVariant()); // [tested]

  /// \brief This function will output (via nsLog) some statistics about which events are used and how often.
  ///
  /// This allows to figure out which events are used throughout the engine and which events might be fired too often.
  static void PrintGlobalEventStatistics(); // [tested]

  /// \brief Updates all global event statistics.
  static void UpdateGlobalEventStatistics();

  /// \brief Returns the map that holds the current statistics about the global events.
  static const EventMap& GetEventStatistics() { return s_KnownEvents; }

private:
  bool m_bOnlyOnce;
  bool m_bHasBeenFired;
  nsStringView m_sEventName;
  NS_GLOBAL_EVENT_HANDLER m_EventHandler;

  static EventMap s_KnownEvents;
};

/// \brief Use this macro to broadcast an event. Pass 0 to 4 parameters of type aeGlobalEventParam to it.
#define NS_BROADCAST_EVENT(name, ...) nsGlobalEvent::Broadcast(#name, ##__VA_ARGS__);

/// \brief Use this macro to handle an event every time it is broadcast (place function code in curly brackets after it)
#define NS_ON_GLOBAL_EVENT(name)                                                                                                       \
  static void EventHandler_##name(const nsVariant& param0, const nsVariant& param1, const nsVariant& param2, const nsVariant& param3); \
  static nsGlobalEvent s_EventHandler_##name(#name, EventHandler_##name, false);                                                       \
  static void EventHandler_##name(const nsVariant& param0, const nsVariant& param1, const nsVariant& param2, const nsVariant& param3)

/// \brief Use this macro to handle an event only once (place function code in curly brackets after it)
#define NS_ON_GLOBAL_EVENT_ONCE(name)                                                                                                  \
  static void EventHandler_##name(const nsVariant& param0, const nsVariant& param1, const nsVariant& param2, const nsVariant& param3); \
  static nsGlobalEvent s_EventHandler_##name(#name, EventHandler_##name, true);                                                        \
  static void EventHandler_##name(const nsVariant& param0, const nsVariant& param1, const nsVariant& param2, const nsVariant& param3)
