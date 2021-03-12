
#include <NTDDK.h> 

VOID drv_unload(PDRIVER_OBJECT pdrvobj);


/*****************************************************************************
 �� �� ��  : DirverEntry
 ��������  : ��ʼ����������
 �������  : pDriverObject
             pRegistryPath
 �������  : ��
 �� �� ֵ  : NTSTATUS
------------------------------------------------------------------------------
 ���һ���޸ļ�¼  : 
 �޸�����  : w00525
 �޸�Ŀ��  :
 �޸�����  : 2015��4��26��
*****************************************************************************/
NTSTATUS DriverEntry(IN PDRIVER_OBJECT pdrvobj,
                       IN PUNICODE_STRING pregpath)
{
    NTSTATUS status = STATUS_SUCCESS;
    DbgPrint("wasadrv:driverentry:begin");
    pdrvobj->DriverUnload = drv_unload; 
    DbgPrint("wasadrv:driverentry:end");
    return status;
}

VOID drv_unload(PDRIVER_OBJECT pdrvobj)
{
    DbgPrint("wasadrv:drv_unload");
}

