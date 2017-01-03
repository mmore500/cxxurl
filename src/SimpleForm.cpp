/**
 * @author : xiaozhuai
 * @date   : 17/1/3
 */

#include "../include/SimpleForm.h"

namespace CXXUrl {

SimpleForm::SimpleForm() :
        Form(Form::SIMPLE) {

}

char* SimpleForm::getData() {
    string queryStr = "";
    map<string, string>::iterator it;
    for (it = formDataMap.begin(); it != formDataMap.end(); it++) {
        queryStr += "&" + it->first + "=" + it->second;
    }
    data = UrlEncode::encode(queryStr.substr(1));
    return data.data();
}

size_t SimpleForm::length() {
    return data.length();
}

void SimpleForm::add(string key, string value) {
    formDataMap[key] = value;
}

}