STATUSES_START
	/////////////// STATUS ////////////////
	
	// GENERIAL:
	STATUSES_ADD_INFO(XENUS_OKAY, kStatusOkay),
	
	 // TLS
	STATUSES_ADD_INFO(XENUS_STATUS_TLS_ALREADY_REGISTERED, kStatusTlsAlreadyRegistered),
	
	 // LISTS:
	STATUSES_ADD_INFO(XENUS_STATUS_LISTS_FOUND, kStatusListsFound),
	STATUSES_ADD_INFO(XENUS_STATUS_LISTS_NOT_FOUND, kStatusListsNotFound),
	STATUSES_ADD_INFO(XENUS_STATUS_LINK_ALREADY_PRESENT, kStatusLinkPresent),

	 // PE: 
	STATUSES_ADD_INFO(XENUS_STATUS_OKAY_PE_INCOMPLETE_IAT, kStatusOkayPEIncompleteIAT),
	STATUSES_ADD_INFO(XENUS_STATUS_OKAY_PE_COMPAT_PROBLEM_MAYBE, kStatusOkayPECompatProblem),
	STATUSES_ADD_INFO(XENUS_STATUS_PE_DATA_DIR_NOT_PRESENT, kStatusPeDataDirNotPresent),
	STATUSES_ADD_INFO(XENUS_STATUS_PE_OKAY_MISSING_OPT_ENTRYPOINT, kStatusMissingEp),
	
	//THREADING
	STATUSES_ADD_INFO(XENUS_STATUS_NESTED_CALL, kStatusNestedCall),

	// LIB LINUX
	STATUSES_ADD_INFO(XENUS_STATUS_BUFFER_NOT_FILLED, kStatusBufferNotFilled),
	
	/////////////// ERRORS ////////////////
	
	 // GENERAL:
	STATUSES_ADD_ERROR(XENUS_ERROR_OUT_OF_MEMORY, kErrorOutOfMemory),
	STATUSES_ADD_ERROR(XENUS_ERROR_GENERIC_FAILURE, kErrorGenericFailure),
	STATUSES_ADD_ERROR(XENUS_ERROR_NOT_IMPLEMENTED, kErrorNotImplemented),
	STATUSES_ADD_ERROR(XENUS_ERROR_BUFFER_OVERFLOW, kErrorBufferOverflow),
	STATUSES_ADD_ERROR(XENUS_ERROR_BUFFER_UNDERFLOW, kErrorBufferUnderflow),
	STATUSES_ADD_ERROR(XENUS_ERROR_ILLEGAL_BAD_ARGUMENT, kErrorIllegalBadArgument),
	STATUSES_ADD_ERROR(XENUS_ERROR_ILLEGAL_SIZE_OVERUNDERFLOW, kErrorIllegalSizeOverunderflow),
	STATUSES_ADD_ERROR(XENUS_ERROR_ILLEGAL_SIZE, kErrorIllegalSize),
	STATUSES_ADD_ERROR(XENUS_ERROR_ILLEGAL_ARG_LENGTH, kErrorIllegalArgLength),
	STATUSES_ADD_ERROR(XENUS_ERROR_ILLEGAL_TYPE, kErrorIllegalType),

	 // STARTUP ERRORS:
//	STATUSES_ADD_ERROR(XENUS_ERROR_LIBX_, KerrorLibX),
	STATUSES_ADD_ERROR(XENUS_ERROR_LIBX_FAILED_TO_CREATE_MUTEX, KerrorLibXThreadingMutexFailed),
	
	
	 // TLS
	STATUSES_ADD_ERROR(XENUS_ERROR_TLS_FAILED_TO_CREATE_LIST, kErrorTlsFailedToCreateList),
	STATUSES_ADD_ERROR(XENUS_ERROR_TLS_FAILED_TO_ADD, kErrorTlsFailedToAdd),
	STATUSES_ADD_ERROR(XENUS_ERROR_TLS_FAILED_TO_DESTORY, kErrorTlsFailedToDestory),
	STATUSES_ADD_ERROR(XENUS_ERROR_TLS_NOT_REGISTERED, kErrorTlsNotRegistered),
	
	  // HASH MAPS:
	STATUSES_ADD_ERROR(XENUS_ERROR_CHAIN_NOT_FOUND, kErrorChainNotFound),
	STATUSES_ADD_ERROR(XENUS_ERROR_LINK_NOT_FOUND, kErrorLinkNotFound),


	STATUSES_ADD_INFO(XENUS_ERROR_LISTS_NOT_FOUND, kErrorListsNotFound),
	
	  // PE LOADER:
	STATUSES_ADD_ERROR(XENUS_ERROR_PE_FAILED_TO_ALLOCATE, kErrorPEFailedToAllocate),
	STATUSES_ADD_ERROR(XENUS_ERROR_PE_BAD_DOS, kErrorPEBadDOS),
	STATUSES_ADD_ERROR(XENUS_ERROR_PE_BAD_PE, kErrorPEBadPE),
	STATUSES_ADD_ERROR(XENUS_ERROR_PE_BAD_SEG, kErrorPEBadSeg),
	STATUSES_ADD_ERROR(XENUS_ERROR_PE_BAD_IMPORTS, kErrorPEBadImports),
	STATUSES_ADD_ERROR(XENUS_ERROR_PE_BAD_IAT, kErrorPEBadIAT),
	STATUSES_ADD_ERROR(XENUS_ERROR_PE_FAILED_TO_RESOLVE_ADDRESS, kErrorPeFailedToResolveAddress),
	STATUSES_ADD_ERROR(XENUS_ERROR_PE_BAD_EXPORTS, kErrorPEBadExports),
	STATUSES_ADD_ERROR(XENUS_ERROR_PE_EXPECTED_MORE_RVASIZES, kErrorPEExpectedMoreRVASizes),
	STATUSES_ADD_ERROR(XENUS_ERROR_PE_BAD_RELOC, kErrorPEBadReloc),
	STATUSES_ADD_ERROR(XENUS_ERROR_PE_NO_DYN_BASE, kErrorPENoDynBase),
	STATUSES_ADD_ERROR(XENUS_ERROR_PE_GENERIC_UNUSUAL_SIZE, kErrorPEGenericUnusualSize),
	STATUSES_ADD_ERROR(XENUS_ERROR_PE_GENERIC_UNUSUAL_ALIGNMENT, kErrorPEGenericUnusualAlignment),
	STATUSES_ADD_ERROR(XENUS_ERROR_PE_GENERIC_UNUSUAL_FAILURE, kErrorPEGenericUnusualFailure),
	STATUSES_ADD_ERROR(XENUS_ERROR_PE_DATA_DIR_NOT_PRESENT, kErrorPEDataDirNotPresent),
	STATUSES_ADD_ERROR(XENUS_ERROR_COULDNT_ALLOCATE_HANDLE, kErrorCouldntAllocateHandle),
	STATUSES_ADD_ERROR(XENUS_ERROR_COULDNT_ALLOCATE_HANDLE_LIST, kErrorCouldntAllocateHandleList),
	STATUSES_ADD_ERROR(XENUS_ERROR_MODULE_NAME_TOO_LONG, kErrorModuleNameTooLong),
	STATUSES_ADD_ERROR(XENUS_ERROR_MODULE_ALREADY_LOADED, kErrorModuleAlreadyLoaded),
	STATUSES_ADD_ERROR(XENUS_ERROR_MODULE_NOT_YET_LOADED, kErrorModuleNotYetLoaded),
	STATUSES_ADD_ERROR(XENUS_ERROR_SYM_NOT_FOUND, kErrorSymNotFound),
	
	  // GENERIC LISTS:
	STATUSES_ADD_ERROR(XENUS_ERROR_LIST_NO_BUFFER, kErrorListNoBuffer),
	STATUSES_ADD_ERROR(XENUS_ERROR_LIST_FAILED_TO_ALLOC_BUFFER, kErrorListFailedToAllocBuffer),
	STATUSES_ADD_ERROR(XENUS_ERROR_LIST_FAILED_TO_RESIZE_BUFFER, kErrorListFailedToResizeBuffer),
	STATUSES_ADD_ERROR(XENUS_ERROR_LIST_INDEX_OUT_BOUNDS, kErrorListIndexOutOfBounds),
	
	  // PORTABLE STRUCTURES ERRORS:
	STATUSES_ADD_ERROR(XENUS_ERROR_SYNED_STRUCTS_BAD_HEAD, kErrorSynedStructsBadHead),
	STATUSES_ADD_ERROR(XENUS_ERROR_SYNED_STRUCTS_BAD_BUF, kErrorSynedStructsBadBuf),


	STATUSES_ADD_ERROR(XENUS_ERROR_NTOS_NOT_FOUND, kErrorNtosNotFound),
	STATUSES_ADD_ERROR(XENUS_ERROR_NTOS_RD_ERR, kErrorGenericNtosReadError),
	STATUSES_ADD_ERROR(XENUS_ERROR_NTOS_MISSING_SYM, kErrorNTOSMissingSym),
	
	// LIB LINUX
	STATUSES_ADD_ERROR(XENUS_ERROR_INTERNAL_ERROR, kErrorInternalError),
	STATUSES_ADD_ERROR(XENUS_ERROR_FILE_HANDLE_NULL, kErrorFileNullHandle),
	STATUSES_ADD_ERROR(XENUS_ERROR_FILE_OPERATION_UNSUPPORTED, kFileOperationUnsupported),
	STATUSES_ADD_ERROR(XENUS_ERROR_UP_DIR_ERROR, kErrorUpDirIssue)
};

STATUSES_DBG_START
#ifdef _DEBUG
	STATUSES_DBG_ADD(XENUS_OKAY, kStatusOkay)
	STATUSES_DBG_ADD(XENUS_STATUS_TLS_ALREADY_REGISTERED, kStatusTlsAlreadyRegistered)
	STATUSES_DBG_ADD(XENUS_STATUS_LISTS_FOUND, kStatusListsFound)
	STATUSES_DBG_ADD(XENUS_STATUS_LISTS_NOT_FOUND, kStatusListsNotFound)
	STATUSES_DBG_ADD(XENUS_STATUS_OKAY_PE_INCOMPLETE_IAT, kStatusOkayPEIncompleteIAT)
	STATUSES_DBG_ADD(XENUS_STATUS_OKAY_PE_COMPAT_PROBLEM_MAYBE, kStatusOkayPECompatProblem)
	STATUSES_DBG_ADD(XENUS_STATUS_NESTED_CALL, kStatusNestedCall)
	STATUSES_DBG_ADD(XENUS_ERROR_OUT_OF_MEMORY, kErrorOutOfMemory)
	STATUSES_DBG_ADD(XENUS_ERROR_GENERIC_FAILURE, kErrorGenericFailure)
	STATUSES_DBG_ADD(XENUS_ERROR_NOT_IMPLEMENTED, kErrorNotImeplemented)
	STATUSES_DBG_ADD(XENUS_ERROR_BUFFER_OVERFLOW, kErrorBufferOverflow)
	STATUSES_DBG_ADD(XENUS_ERROR_BUFFER_UNDERFLOW, kErrorBufferUnderflow)
	STATUSES_DBG_ADD(XENUS_ERROR_ILLEGAL_BAD_ARGUMENT, kErrorIllegalBadArgument)
	STATUSES_DBG_ADD(XENUS_ERROR_ILLEGAL_SIZE_OVERUNDERFLOW, kErrorIllegalSizeOverunderflow)
	STATUSES_DBG_ADD(XENUS_ERROR_ILLEGAL_SIZE, kErrorIllegalSize)
	STATUSES_DBG_ADD(XENUS_ERROR_LIBX_FAILED_TO_CREATE_MUTEX, KerrorLibXThreadingMutexFailed)
	STATUSES_DBG_ADD(XENUS_ERROR_TLS_FAILED_TO_CREATE_LIST, kErrorTlsFailedToCreateList)
	STATUSES_DBG_ADD(XENUS_ERROR_TLS_FAILED_TO_ADD, kErrorTlsFailedToAdd)
	STATUSES_DBG_ADD(XENUS_ERROR_TLS_FAILED_TO_DESTORY, kErrorTlsFailedToDestory)
	STATUSES_DBG_ADD(XENUS_ERROR_TLS_NOT_REGISTERED, kErrorTlsNotRegistered)
	STATUSES_DBG_ADD(XENUS_ERROR_CHAIN_NOT_FOUND, kErrorChainNotFound)
	STATUSES_DBG_ADD(XENUS_ERROR_LINK_NOT_FOUND, kErrorLinkNotFound)
//	STATUSES_DBG_ADD(XENUS_ERROR_LINK_ALREADY_PRESENT, kErrorChainAlreadyPresent)
	STATUSES_DBG_ADD(XENUS_ERROR_PE_FAILED_TO_ALLOCATE, kErrorPEFailedToAllocate)
	STATUSES_DBG_ADD(XENUS_ERROR_PE_BAD_DOS, kErrorPEBadDOS)
	STATUSES_DBG_ADD(XENUS_ERROR_PE_BAD_PE, kErrorPEBadPE)
	STATUSES_DBG_ADD(XENUS_ERROR_PE_BAD_SEG, kErrorPEBadSeg)
	STATUSES_DBG_ADD(XENUS_ERROR_PE_BAD_IMPORTS, kErrorPEBadImports)
	STATUSES_DBG_ADD(XENUS_ERROR_PE_BAD_IAT, kErrorPEBadIAT)
	STATUSES_DBG_ADD(XENUS_ERROR_PE_FAILED_TO_RESOLVE_ADDRESS, kErrorPeFailedToResolveAddress)
	STATUSES_DBG_ADD(XENUS_ERROR_PE_BAD_EXPORTS, kErrorPEBadExports)
	STATUSES_DBG_ADD(XENUS_ERROR_PE_EXPECTED_MORE_RVASIZES, kErrorPEExpectedMoreRVASizes)
	STATUSES_DBG_ADD(XENUS_ERROR_PE_BAD_RELOC, kErrorPEBadReloc)
	STATUSES_DBG_ADD(XENUS_ERROR_PE_NO_DYN_BASE, kErrorPENoDynBase)
	STATUSES_DBG_ADD(XENUS_ERROR_PE_GENERIC_UNUSUAL_SIZE, kErrorPEGenericUnusualSize)
	STATUSES_DBG_ADD(XENUS_ERROR_PE_GENERIC_UNUSUAL_ALIGNMENT, kErrorPEGenericUnusualAlignment)
	STATUSES_DBG_ADD(XENUS_ERROR_PE_GENERIC_UNUSUAL_FAILURE, kErrorPEGenericUnusualFailure)
	STATUSES_DBG_ADD(XENUS_ERROR_PE_DATA_DIR_NOT_PRESENT, kStatusPEDataDirNotPresent)
	STATUSES_DBG_ADD(XENUS_ERROR_LIST_NO_BUFFER, kErrorListNoBuffer)
	STATUSES_DBG_ADD(XENUS_ERROR_LIST_FAILED_TO_ALLOC_BUFFER, kErrorListFailedToAllocBuffer)
	STATUSES_DBG_ADD(XENUS_ERROR_LIST_FAILED_TO_RESIZE_BUFFER, kErrorListFailedToResizeBuffer)
	STATUSES_DBG_ADD(XENUS_ERROR_LIST_INDEX_OUT_BOUNDS, kErrorListIndexOutOfBounds)
	STATUSES_DBG_ADD(XENUS_ERROR_SYNED_STRUCTS_BAD_HEAD, kErrorSynedStructsBadHead)
	STATUSES_DBG_ADD(XENUS_ERROR_SYNED_STRUCTS_BAD_BUF, kErrorSynedStructsBadBuf)
	
#else
    STATUSES_DBG_ADD(XENUS_OKAY, kErrorOkay)
#endif
STATUSES_DBG_END