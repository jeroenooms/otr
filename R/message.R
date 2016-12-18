#' OTR Messaging
#'
#' Encrypt and decrypt messages for use in OTR.
#'
#' @param msg text message
#' @useDynLib otr C_send_message
otr_send <- function(msg) {
  .Call(C_send_message, msg)
}

#' @export
#' @useDynLib otr C_otr_version
otr_config <- function(){
  version <- .Call(C_otr_version)
  list(version = version)
}
