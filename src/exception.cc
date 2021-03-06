#include "exception.hh"

BaseException::BaseException(
        const char*         aFileName,
        const unsigned int  aLineNumber,
        const char*         aFunctionName,
        const char*         aErrorMessage) :
    std::runtime_error(aErrorMessage),
	_file(aFileName),
	_line(aLineNumber),
	_func(aFunctionName)
	//_errMsg(aErrorMessage)
{}

BaseException::BaseException(
        const std::string&  aFileName,
        const unsigned int  aLineNumber,
        const std::string&  aFunctionName,
        const std::string&  aErrorMessage) :
    std::runtime_error(aErrorMessage),
	_file(aFileName),
	_line(aLineNumber),
	_func(aFunctionName)
{}

BaseException::BaseException(const BaseException& aException) :
    std::runtime_error(aException.what()),
	_file(aException._file),
	_line(aException._line),
	_func(aException._func)
{}

void BaseException::print() const
{
  std::cerr << "An error occured in " << _file
      << ", line " << _line
      << ", '" << _func
      << "':\n\t\"" << what() << "\""
      << std::endl;
}

SingletonException::SingletonException(
        const char*         aFileName,
        const unsigned int  aLineNumber,
        const char*         aFunctionName) :
	BaseException(
            aFileName,
            aLineNumber,
            aFunctionName,
            "Cannot return reference to uninstantiated singleton.")
{}

OutOfMemoryException::OutOfMemoryException(
        const char*         aFileName,
        const unsigned int  aLineNumber,
        const char*         aFunctionName) :
	BaseException(
            aFileName,
            aLineNumber,
            aFunctionName,
            "There was insufficient memory to fulfill the allocation request.")
{}

InvalidArgumentException::InvalidArgumentException(
        const char*         aFileName,
        const unsigned int  aLineNumber,
        const char*         aFunctionName,
        const std::string&  aErrorMessage) :
	BaseException(
            aFileName,
            aLineNumber,
            aFunctionName,
            aErrorMessage)
{}

SwitchException::SwitchException(
        const char*         aFileName,
        const unsigned int  aLineNumber,
        const char*         aFunctionName) :
	BaseException(
            aFileName,
            aLineNumber,
            aFunctionName,
            "Default section in switch-statement accessed.")
{}

FileException::FileException(
        const char*         aFileName,
        const unsigned int  aLineNumber,
        const char*         aFunctionName,
        const char*         aErrorFileName,
        const std::string&  aErrorMessage) :
	BaseException(
            aFileName,
            aLineNumber,
            aFunctionName,
            "Problem in file " + std::string(aErrorFileName) + ": " + aErrorMessage)
{}

VectorException::VectorException(
	const char*         aFileName,
	const unsigned int  aLineNumber,
	const char*         aFunctionName,
	const std::string&  aErrorMessage) :
	BaseException(
	    aFileName,
            aLineNumber,
            aFunctionName,
            aErrorMessage)
{}
