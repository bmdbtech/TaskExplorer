#ifndef _PH_XPHUSERP_H
#define _PH_XPHUSERP_H

typedef NTSTATUS (NTAPI *PKPHP_WITH_KEY_CONTINUATION)(
    _In_ KPH_KEY Key,
    _In_ PVOID Context
    );

NTSTATUS NTAPI XphpDeviceIoControl(
    _In_ ULONG XphControlCode,
    _In_ PVOID InBuffer,
    _In_ ULONG InBufferLength
    );

typedef struct _KPHP_RETRIEVE_KEY_CONTEXT
{
    IO_STATUS_BLOCK Iosb;
    PKPHP_WITH_KEY_CONTINUATION Continuation;
    PVOID Context;
    NTSTATUS Status;
} KPHP_RETRIEVE_KEY_CONTEXT, *PKPHP_RETRIEVE_KEY_CONTEXT;

VOID NTAPI XphpWithKeyApcRoutine(
    _In_ PVOID ApcContext,
    _In_ PIO_STATUS_BLOCK IoStatusBlock,
    _In_ ULONG Reserved
    );

NTSTATUS NTAPI XphpWithKey(
    _In_ KPH_KEY_LEVEL KeyLevel,
    _In_ PKPHP_WITH_KEY_CONTINUATION Continuation,
    _In_ PVOID Context
    );

// Get L1 key

typedef struct _KPHP_GET_L1_KEY_CONTEXT
{
    PKPH_KEY Key;
} KPHP_GET_L1_KEY_CONTEXT, *PKPHP_GET_L1_KEY_CONTEXT;

NTSTATUS NTAPI XphpGetL1KeyContinuation(
    _In_ KPH_KEY Key,
    _In_ PVOID Context
    );

NTSTATUS NTAPI XphpGetL1Key(
    _Inout_ PKPH_KEY Key
    );

// Open process

typedef struct _KPH_OPEN_PROCESS_INPUT
{
    PHANDLE ProcessHandle;
    ACCESS_MASK DesiredAccess;
    PCLIENT_ID ClientId;
    KPH_KEY Key;
} KPH_OPEN_PROCESS_INPUT, *PKPH_OPEN_PROCESS_INPUT;

NTSTATUS NTAPI XphpOpenProcessContinuation(
    _In_ KPH_KEY Key,
    _In_ PVOID Context
    );

// Open process token

typedef struct _KPH_OPEN_PROCESS_TOKEN_INPUT
{
    HANDLE ProcessHandle;
    ACCESS_MASK DesiredAccess;
    PHANDLE TokenHandle;
    KPH_KEY Key;
} KPH_OPEN_PROCESS_TOKEN_INPUT, *PKPH_OPEN_PROCESS_TOKEN_INPUT;

NTSTATUS NTAPI XphpOpenProcessTokenContinuation(
    _In_ KPH_KEY Key,
    _In_ PVOID Context
    );

// Terminate process

typedef struct _KPH_TERMINATE_PROCESS_INPUT
{
    HANDLE ProcessHandle;
    NTSTATUS ExitStatus;
    KPH_KEY Key;
} KPH_TERMINATE_PROCESS_INPUT, *PKPH_TERMINATE_PROCESS_INPUT;

NTSTATUS NTAPI XphpTerminateProcessContinuation(
    _In_ KPH_KEY Key,
    _In_ PVOID Context
    );

// Read virtual memory, unsafe

typedef struct _KPH_READ_VIRTUAL_MEMORY_UNSAFE_INPUT
{
    HANDLE ProcessHandle;
    PVOID BaseAddress;
    PVOID Buffer;
    SIZE_T BufferSize;
    PSIZE_T NumberOfBytesRead;
    KPH_KEY Key;
} KPH_READ_VIRTUAL_MEMORY_UNSAFE_INPUT, *PKPH_READ_VIRTUAL_MEMORY_UNSAFE_INPUT;

NTSTATUS NTAPI XphpReadVirtualMemoryUnsafeContinuation(
    _In_ KPH_KEY Key,
    _In_ PVOID Context
    );

// Open thread

typedef struct _KPH_OPEN_THREAD_INPUT
{
    PHANDLE ThreadHandle;
    ACCESS_MASK DesiredAccess;
    PCLIENT_ID ClientId;
    KPH_KEY Key;
} KPH_OPEN_THREAD_INPUT, *PKPH_OPEN_THREAD_INPUT;

NTSTATUS NTAPI XphpOpenThreadContinuation(
    _In_ KPH_KEY Key,
    _In_ PVOID Context
    );

#endif
