#pragma once

enum class ValType {
	Password, Phone, GSM, EMail
};

enum class ErrorType {
	No_Error, Wrong_Amount_Of_Parameters, Wrong_Type, File_Open_Failed, Wrong_Input, Invalid_Cast, File_Write_Failed, Session_Data_Missing, Null_Pointer
};
