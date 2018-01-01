#include "Arduino.h"
#include "Log2String.h"


void Log2String::init () {
  _bSendRequired = true;
  _sValue = "";
  _sLastValue = "";
//  _cValue = "";
  _sValueName = "";
//  _cValueName = "";
  _iValueChange = 0;
  _fValueChange = 0;
  _iValueType = 0;
}
	
void Log2String::setValue(String tsValue) {
  _sValue = tsValue;
  _iValueType = 1;
}

void Log2String::setValue(int tiValue) {
  _iValue = tiValue;
  _sValue = String(tiValue);
  _iValueType = 2;
}

void Log2String::setValue(float tfValue) {
  _fValue = tfValue;
  _sValue = String(tfValue);
  _iValueType = 3;
}

void Log2String::setValue(boolean tbValue) {
  _bValue = tbValue; 
  _sValue = String(tbValue);
  _iValueType = 4;
}

void Log2String::setValueChange(float tfValueChange){
	_fValueChange = tfValueChange;
}
	
void Log2String::setTimeBetweenSend(int tiTimeBetweenSend) {
  _iTimeBetweenSend = tiTimeBetweenSend;
}

String Log2String::getValue() {
  return _sValue;
}

char* Log2String::getCValue() {
	_sValue.toCharArray(_cValue, _sValue.length() + 1); //kopier String _sValue in den Char _cValue
  return _cValue;
}

void Log2String::setValueName(String tsValueName) {
  _sValueName = tsValueName;
}

String Log2String::getValueName() {
  return _sValueName;
}

char* Log2String::getCValueName() {
	_sValueName.toCharArray(_cValueName, _sValueName.length() + 1); //kopier String _sValueName in den Char _cValueName
  return _cValueName;
}

void Log2String::setSendNow(){
		_lCurrentMillis = millis();
		_sLastValue = _sValue;
		_bLastValue = _bValue;
		_iLastValue = _iValue;
		_fLastValue = _fValue;
		_bSendRequired = false;
	}
	
void Log2String::setSendRequired(bool tbSendRequired) {
	_bSendRequired = tbSendRequired;
}

bool Log2String::getSendRequired() {
			
	if ((millis() - _lCurrentMillis) > _iTimeBetweenSend) {
		_bSendRequired = true;
	}else{
		if (_iValueType == 1){ //String
			if (_sValue != _sLastValue) {
			_bSendRequired = true;
			}	
		}
		
		if (_iValueType == 4){ //Bool
			if (_bValue != _bLastValue) {
			_bSendRequired = true;
			}	
		}
		
		if (_iValueType == 2){ //Int
			if (_iValue != _iLastValue) {
			    _bSendRequired = true;
			}	
		}
		
		if (_iValueType == 3){ //Flow
			if (abs(_fValue - _fLastValue) > _fValueChange) {
			    _bSendRequired = true;
			}	
		}
	}
	
	return _bSendRequired;	
}



