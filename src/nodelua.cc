#include <node.h>
#include <v8.h>
#include <nan.h>

#include "luastate.h"
#ifndef WIN32
# include <unistd.h>
#else
//TODO
#endif

extern "C" {
	#include <lua.h>
}

using namespace v8;

void init_info_constants(v8::Local<v8::Object> target){
  Local<Object> constants = Nan::New<v8::Object>();
    (void)constants->Set(Nan::GetCurrentContext(), Nan::New("VERSION").ToLocalChecked(),Nan::New(LUA_VERSION).ToLocalChecked());
    (void)constants->Set(Nan::GetCurrentContext(), Nan::New("VERSION_NUM").ToLocalChecked(), Nan::New(LUA_VERSION_NUM));
    (void)constants->Set(Nan::GetCurrentContext(), Nan::New("COPYRIGHT").ToLocalChecked(), Nan::New(LUA_COPYRIGHT).ToLocalChecked());
    (void)constants->Set(Nan::GetCurrentContext(), Nan::New("AUTHORS").ToLocalChecked(), Nan::New(LUA_AUTHORS).ToLocalChecked());
    (void)target->Set(Nan::GetCurrentContext(), Nan::New("INFO").ToLocalChecked(), constants);
}

void init_status_constants(v8::Local<v8::Object> target){
    Local<Object> constants = Nan::New<v8::Object>();
    (void)constants->Set(Nan::GetCurrentContext(), Nan::New("YIELD").ToLocalChecked(), Nan::New(LUA_YIELD));
    (void)constants->Set(Nan::GetCurrentContext(), Nan::New("ERRRUN").ToLocalChecked(), Nan::New(LUA_ERRRUN));
    (void)constants->Set(Nan::GetCurrentContext(), Nan::New("ERRSYNTAX").ToLocalChecked(), Nan::New(LUA_ERRSYNTAX));
    (void)constants->Set(Nan::GetCurrentContext(), Nan::New("ERRMEM").ToLocalChecked(), Nan::New(LUA_ERRMEM));
    (void)constants->Set(Nan::GetCurrentContext(), Nan::New("ERRERR").ToLocalChecked(), Nan::New(LUA_ERRERR));
    (void)target->Set(Nan::GetCurrentContext(), Nan::New("STATUS").ToLocalChecked(), constants);
}

void init_gc_constants(v8::Local<v8::Object> target){
    Local<Object> constants = Nan::New<v8::Object>();
    (void)constants->Set(Nan::GetCurrentContext(), Nan::New("STOP").ToLocalChecked(), Nan::New(LUA_GCSTOP));
    (void)constants->Set(Nan::GetCurrentContext(), Nan::New("RESTART").ToLocalChecked(), Nan::New(LUA_GCRESTART));
    (void)constants->Set(Nan::GetCurrentContext(), Nan::New("COLLECT").ToLocalChecked(), Nan::New(LUA_GCCOLLECT));
    (void)constants->Set(Nan::GetCurrentContext(), Nan::New("COUNT").ToLocalChecked(), Nan::New(LUA_GCCOUNT));
    (void)constants->Set(Nan::GetCurrentContext(), Nan::New("COUNTB").ToLocalChecked(), Nan::New(LUA_GCCOUNTB));
    (void)constants->Set(Nan::GetCurrentContext(), Nan::New("STEP").ToLocalChecked(), Nan::New(LUA_GCSTEP));
    (void)constants->Set(Nan::GetCurrentContext(), Nan::New("SETPAUSE").ToLocalChecked(), Nan::New(LUA_GCSETPAUSE));
    (void)constants->Set(Nan::GetCurrentContext(), Nan::New("SETSTEPMUL").ToLocalChecked(), Nan::New(LUA_GCSETSTEPMUL));
    (void)target->Set(Nan::GetCurrentContext(), Nan::New("GC").ToLocalChecked(), constants);
}

void init_lua_constants(v8::Local<v8::Object> target){
    Local<Object> constants = Nan::New<v8::Object>();
    (void)constants->Set(Nan::GetCurrentContext(), Nan::New("GLOBALSINDEX").ToLocalChecked(), Nan::New(LUA_GLOBALSINDEX));
    (void)target->Set(Nan::GetCurrentContext(), Nan::New("LUA").ToLocalChecked(), constants);
}

void init(v8::Local<v8::Object> exports, v8::Local<v8::Object> module) {
 	LuaState::Init(exports);
    init_gc_constants(exports);
    init_status_constants(exports);
    init_info_constants(exports);
	init_lua_constants(exports);
    // printf("node-lua loaded\n");
    fflush(stdout);
}
NODE_MODULE(nodelua, init)
