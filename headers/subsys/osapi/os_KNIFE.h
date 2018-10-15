XENUS_IMPORT void free_task(task_k tsk);
XENUS_IMPORT void __put_task_struct(task_k tsk);
XENUS_IMPORT void __mmdrop(mm_struct_k mm);
XENUS_IMPORT void mmput(mm_struct_k mm);
XENUS_IMPORT file_k get_mm_exe_file(mm_struct_k mm);
XENUS_IMPORT file_k get_task_exe_file(task_k task);
XENUS_IMPORT mm_struct_k get_task_mm(task_k task);
