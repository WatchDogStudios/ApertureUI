#include <Foundation/FoundationPCH.h>

NS_STATICLINK_LIBRARY(Foundation)
{
  if (bReturn)
    return;

  NS_STATICLINK_REFERENCE(Foundation_Application_Config_Implementation_FileSystemConfig);
  NS_STATICLINK_REFERENCE(Foundation_Application_Config_Implementation_PluginConfig);
  NS_STATICLINK_REFERENCE(Foundation_CodeUtils_Expression_Implementation_ExpressionByteCode);
  NS_STATICLINK_REFERENCE(Foundation_CodeUtils_Expression_Implementation_ExpressionDeclarations);
  NS_STATICLINK_REFERENCE(Foundation_Communication_Implementation_Message);
  NS_STATICLINK_REFERENCE(Foundation_Communication_Implementation_MessageLoop);
  NS_STATICLINK_REFERENCE(Foundation_Communication_Implementation_RemoteMessage);
  NS_STATICLINK_REFERENCE(Foundation_Configuration_Implementation_CVar);
  NS_STATICLINK_REFERENCE(Foundation_DataProcessing_Stream_DefaultImplementations_Implementation_ZeroInitializer);
  NS_STATICLINK_REFERENCE(Foundation_DataProcessing_Stream_Implementation_ProcessingStreamProcessor);
  NS_STATICLINK_REFERENCE(Foundation_IO_Archive_Implementation_DataDirTypeArchive);
  NS_STATICLINK_REFERENCE(Foundation_IO_FileSystem_Implementation_DataDirTypeFolder);
  NS_STATICLINK_REFERENCE(Foundation_IO_FileSystem_Implementation_FileSystem);
  NS_STATICLINK_REFERENCE(Foundation_Logging_Implementation_LogEntry);
  NS_STATICLINK_REFERENCE(Foundation_Math_Implementation_Math);
  NS_STATICLINK_REFERENCE(Foundation_Memory_Implementation_FrameAllocator);
  NS_STATICLINK_REFERENCE(Foundation_Platform_Win_DirectoryWatcher_Win);
  NS_STATICLINK_REFERENCE(Foundation_Profiling_Implementation_Profiling);
  NS_STATICLINK_REFERENCE(Foundation_Reflection_Implementation_PropertyAttributes);
  NS_STATICLINK_REFERENCE(Foundation_Reflection_Implementation_PropertyPath);
  NS_STATICLINK_REFERENCE(Foundation_Reflection_Implementation_RTTI);
  NS_STATICLINK_REFERENCE(Foundation_Reflection_Implementation_StandardTypes);
  NS_STATICLINK_REFERENCE(Foundation_Serialization_Implementation_AbstractObjectGraph);
  NS_STATICLINK_REFERENCE(Foundation_Serialization_Implementation_GraphVersioning);
  NS_STATICLINK_REFERENCE(Foundation_System_Implementation_StackTracer);
  NS_STATICLINK_REFERENCE(Foundation_Threading_Implementation_TaskSystem);
  NS_STATICLINK_REFERENCE(Foundation_Threading_Implementation_ThreadUtils);
  NS_STATICLINK_REFERENCE(Foundation_Time_Implementation_Clock);
  NS_STATICLINK_REFERENCE(Foundation_Time_Implementation_Time);
  NS_STATICLINK_REFERENCE(Foundation_Time_Implementation_Timestamp);
  NS_STATICLINK_REFERENCE(Foundation_Types_Implementation_VarianceTypes);
  NS_STATICLINK_REFERENCE(Foundation_Types_Implementation_VariantTypeRegistry);
}