function(carbin_debug)
    if (CARBIN_STATUS_DEBUG)
        string(TIMESTAMP timestamp)
        if (CARBIN_CACHE_RUN)
            set(type "DEBUG (CACHE RUN)")
        else ()
            set(type "DEBUG")
        endif ()
        message(STATUS "[carbin *** ${type} *** ${timestamp}] ${ARGV}")
    endif ()
endfunction(carbin_debug)

function(carbin_print)
    if (CARBIN_STATUS_PRINT OR CARBIN_STATUS_DEBUG)
        if (CARBIN_CACHE_RUN)
            hunter_status_debug("${ARGV}")
        else ()
            message(STATUS "[carbin] ${ARGV}")
        endif ()
    endif ()
endfunction(carbin_print)