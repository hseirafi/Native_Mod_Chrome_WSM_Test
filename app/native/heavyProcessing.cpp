#include <nan.h>
#include <string>

using namespace v8;
void Sum(const v8::FunctionCallbackInfo<v8::Value>& args){

v8::Isolate* isolate= args.GetIsolate();
int i;
double a = 3.141592;
double b = 2.718; 
for(i=0; i<1000000; i++){
a += b;

}
std::string sText = "v8 test";
// auto total = v8::Number::New(isolate, a); 
// args.GetReturnValue().Set(total); 
//auto hTextJS = v8::String::NewFromUtf8(isolate, sText.c_str(), v8::NewStringType::kNormal );
Local<String> retval = String::NewFromUtf8(isolate, sText.c_str());
  args.GetReturnValue().Set(retval);
//  args.GetReturnValue().Set(v8::String::NewFromUtf8(
//       isolate, "helll world ", v8::NewStringType::kNormal).ToLocalChecked());
}


void Initialize(Local<Object> exports){
    NODE_SET_METHOD(exports, "sum", Sum);
}

NODE_MODULE(addon, Initialize)
