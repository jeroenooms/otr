#include <Rinternals.h>
#include <libotr/proto.h>
#include <libotr/message.h>
#include <libotr/instag.h>

OtrlUserState userstate;

SEXP C_send_message(SEXP msg){
  char * out = NULL;
  const OtrlMessageAppOps ui_ops;
  void * opdata = NULL;
  const char * accountname = "jerry";
  const char * protocolid = "test";
  const char * recipient_name = "jimmy";
  const char * message = CHAR(STRING_ELT(msg, 0));
  otrl_instag_t instag = otrl_instag_get_new();
  OtrlFragmentPolicy fragPolicy = OTRL_FRAGMENT_SEND_SKIP;
  ConnContext * contextp = NULL;


  gcry_error_t err = otrl_message_sending(userstate, &ui_ops, opdata, accountname,
                             protocolid, recipient_name, instag, message, NULL,
                             &out, fragPolicy, &contextp, NULL, NULL);

  return mkString(out);
}
