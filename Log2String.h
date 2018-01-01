#ifndef Log2String_h
#define Log2String_h


class Log2String {
  public:
    void init(); 
	
    void setValue(String tsValue);
    void setValue(int tiValue);
    void setValue(float tfValue);
    void setValue(boolean tbValue);
	
	void setValueChange(float tfValueChange);
	
    String getValue();
    char* getCValue();	
	
    void setValueName(String tsValueName);

    String getValueName();
    char* getCValueName();
	
	void setTimeBetweenSend(int tiTimeBetweenSend);
	
	void setSendRequired(bool tbSendRequired);
	bool getSendRequired();
	
	void setSendNow();

  private:

	String _sValue;
	String _sLastValue;
  	char _cValue[10];
	int  _iValueType;
		
	int _iValue;
	int _iLastValue;
	int _iValueChange;
	
	float _fValue;
	float _fLastValue;
	float _fValueChange;
	
	bool _bValue;
	bool _bLastValue;
	
	String _sValueName;
  	char _cValueName[30];
	
	unsigned long _lCurrentMillis;
	int _iTimeBetweenSend;
	bool _bSendRequired;
	
};	
	
#endif