function(carbin_error)
    message("")
    foreach (print_message ${ARGV})
        message(SEND_ERROR "[carbin ** INTERNAL **] ${print_message}")
    endforeach ()
    message(FATAL_ERROR "[carbin ** INTERNAL **] [Directory:${CMAKE_CURRENT_LIST_DIR}]")
    message("")
endfunction(carbin_error)