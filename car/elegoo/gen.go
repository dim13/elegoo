package main

//go:generate sh -c "protoc -I.. --go_out=. ../*.proto"
//go:generate sh -c "protoc -I.. --nanopb_out=.. ../*.proto"
