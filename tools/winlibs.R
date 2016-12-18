# Build against mingw-w64 build of libotr 4.1.1
if(!file.exists("../windows/libotr-4.1.1/include/libotr/proto.h")){
  if(getRversion() < "3.3.0") setInternet2()
  download.file("https://github.com/rwinlib/libotr/archive/v4.1.1.zip", "lib.zip", quiet = TRUE)
  dir.create("../windows", showWarnings = FALSE)
  unzip("lib.zip", exdir = "../windows")
  unlink("lib.zip")
}
