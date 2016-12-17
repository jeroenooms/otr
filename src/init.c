#include <R_ext/Rdynload.h>
#include <Rinternals.h>
#include <libotr/proto.h>

OtrlUserState userstate = NULL;

#define exit(x) Rf_error("init error");

void R_init_otr(DllInfo *info) {
  OTRL_INIT;
  userstate = otrl_userstate_create();
}

void R_unload_otr(DllInfo *info) {
  otrl_userstate_free(userstate);
}
