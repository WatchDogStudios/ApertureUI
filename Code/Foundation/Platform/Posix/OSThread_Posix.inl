#include <Foundation/Threading/Implementation/OSThread.h>
#include <Foundation/Threading/Thread.h>

nsAtomicInteger32 nsOSThread::s_iThreadCount;

// Posix specific implementation of the thread class

nsOSThread::nsOSThread(nsOSThreadEntryPoint pThreadEntryPoint, void* pUserData /*= nullptr*/, nsStringView sName /*= "nsThread"*/, nsUInt32 uiStackSize /*= 128 * 1024*/)
{
  s_iThreadCount.Increment();

  m_EntryPoint = pThreadEntryPoint;
  m_pUserData = pUserData;
  m_sName = sName;
  m_uiStackSize = uiStackSize;

  // Thread creation is deferred since Posix threads can't be created sleeping
}

nsOSThread::~nsOSThread()
{
  s_iThreadCount.Decrement();
}

/// Starts the thread
void nsOSThread::Start()
{
  pthread_attr_t ThreadAttributes;
  pthread_attr_init(&ThreadAttributes);
  pthread_attr_setdetachstate(&ThreadAttributes, PTHREAD_CREATE_JOINABLE);
  pthread_attr_setstacksize(&ThreadAttributes, m_uiStackSize);

  int iReturnCode = pthread_create(&m_hHandle, &ThreadAttributes, m_EntryPoint, m_pUserData);
  NS_IGNORE_UNUSED(iReturnCode);
  NS_ASSERT_RELEASE(iReturnCode == 0, "Thread creation failed!");

#ifdef NS_POSIX_THREAD_SETNAME
  if (iReturnCode == 0 && !m_sName.IsEmpty())
  {
    // pthread has a thread name limit of 16 bytes.
    // This means 15 characters and the terminating '\0'
    if (m_sName.GetElementCount() < 16)
    {
      pthread_setname_np(m_hHandle, m_sName.GetData());
    }
    else
    {
      char threadName[16];
      strncpy(threadName, m_sName.GetData(), 15);
      threadName[15] = '\0';
      pthread_setname_np(m_hHandle, threadName);
    }
  }
#endif

  m_ThreadID = m_hHandle;

  pthread_attr_destroy(&ThreadAttributes);
}

/// Joins with the thread (waits for termination)
void nsOSThread::Join()
{
  pthread_join(m_hHandle, nullptr);
}
