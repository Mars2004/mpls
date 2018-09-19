# MarsTech Promise Like Syntax
 - [Instalation](#Instalation)
	 - [Configuration](#Configuration)
 - [MSV_PROMISE_DEFINE_ARGS[n]](#MSV_PROMISE_DEFINE_ARGS[n])
 - [MSV_PROMISE and MSV_PROMISE_ARGS[n]](#MSV_PROMISE-and-MSV_PROMISE_ARGS[n])
 - [MSV_PROMISE_THEN and MSV_PROMISE_THEN_ARGS[n]](#MSV_PROMISE_THEN-and-MSV_PROMISE_THEN_ARGS[n])
 - [MSV_PROMISE_THEN_CONTINUE and MSV_PROMISE_THEN_CONTINUE_ARGS[n]](#MSV_PROMISE_THEN_CONTINUE-and-MSV_PROMISE_THEN_CONTINUE_ARGS[n])
 - [MSV_PROMISE_CATCH](#MSV_PROMISE_CATCH)
 - [Source code documentation](#Source-code-documentation)
 - [License](#License)

MarsTech Promise Like Syntax (MPLS) is a C++ project to allow control returned errorcodes similar to promises. The project does not implement promises, it is only set of macros which allows to write code similar to (JavaScript) promises. 

So, for what is it good? Sometimes if we need check returned errorcodes we can get into `if - else` hell like this:
~~~cpp
int errorcode = 0;  
if (FAILED(errorcode = returnsErrorcode()))
{
	//log/return/etc.
}
else if (SUCCEEDED(errorcode = returnsErrorcode()))
{
	if (FAILED(errorcode = returnsErrorcode()))
	{
		//log/return/etc.
	}
	//...
}
~~~

Ok, what to do if we want to check all returned errorcodes and stop execution when error occured? We can use `do { } while(false);` loop:
~~~cpp  
int errorcode = 0;
do
{
	if (FAILED(errorcode = returnsErrorcode()))
	{
		//log/return/etc.
		break;
	}

	if (FAILED(errorcode = returnsErrorcode()))
	{
		//log/return/etc.
		break;
	}

	if (FAILED(errorcode = returnsErrorcode()))
	{
		//log/return/etc.
		break;
	}
} while (false);

if (FAILED(errorcode))
{
	//log/return/etc.
}
~~~

I think it is much better to understand this version then the first one. But still it is a huge number of lines to write this code and many of them are same or similar. There is time for MPLS project - it is set of macros which generates codes above. Lets look, how would previous code could look like with MPLS:
~~~cpp
MSV_PROMISE(returnsErrorcode(), /* log/return/etc. */)
MSV_PROMISE_THEN(returnsErrorcode(), /* log/return/etc. */)
MSV_PROMISE_THEN(returnsErrorcode(), /* log/return/etc. */)
MSV_PROMISE_CATCH(/* log/return/etc. */)
~~~

Doesn't it looks better then other two examples above? It is self explained and minimal.

## Instalation
MPLS is header only project/library - there is no static or dynamic library. You can download repository and include header file mpls.h to your project.

### Configuration
MPLS needs to know your errorcode type, your success errorcode and FAILED handler (function or macro which returns true for errors). You can set it by three macros before including header file mpls.h:

 - **MSV_PROMISE_LIKE_ERRORCODE_TYPE** - your errorcode type. Default is `int32_t`.
 - **MSV_PROMISE_LIKE_ERRORCODE_NOERROR** - success errorcode. Default is `0`.
 - **MSV_PROMISE_LIKE_FAILED(errorcode)** - error check (returns true for errors). Default is `((errorcode) != MSV_PROMISE_LIKE_ERRORCODE_NOERROR)`.
 
You can define this macros in your compiler or maybe better solution is to create your own header file for MPLS where you can define those macros and include header file mpls.h after them.
**Example:**
~~~cpp
#define MSV_PROMISE_LIKE_ERRORCODE_TYPE MyOwnErrorcode
#define MSV_PROMISE_LIKE_ERRORCODE_NOERROR MyOwnSuccessErrorcode
#define MSV_PROMISE_LIKE_FAILED(errorcode) MY_OWN_FAILED(errorcode)

#include "mpls.h"
~~~
Then you can include your own MPLS header file to your source files in your project.

## MSV_PROMISE_DEFINE_ARGS[n]
Defines (output) arguments for next [MSV_PROMISE_THEN](#MSV_PROMISE_THEN-and-MSV_PROMISE_THEN_ARGS[n]). There are these versions of MSV_PROMISE_DEFINE_ARGS[n] macros:

 - MSV_PROMISE_DEFINE_ARGS1
 - MSV_PROMISE_DEFINE_ARGS2
 - MSV_PROMISE_DEFINE_ARGS3
 - MSV_PROMISE_DEFINE_ARGS4
 - MSV_PROMISE_DEFINE_ARGS5
 
The number at the end of macro name is a number of defined arguments up to five.
**Examples:**
~~~cpp
MSV_PROMISE_DEFINE_ARGS1(int x);					//generates:	int x;
MSV_PROMISE_DEFINE_ARGS2(int x = 1, int y = 2);		//generates:	int x = 1; int y = 2;
~~~

## MSV_PROMISE and MSV_PROMISE_ARGS[n]
Promise entry point and the first checked call. If the call failes it breaks, executes request action or actions (can be any number of actions) and [MSV_PROMISE_CATCH](#MSV_PROMISE_CATCH) is executed. No next checked call is executed.  
There are these versions of MSV_PROMISE and MSV_PROMISE_ARGS[n] macros:

 - MSV_PROMISE
 - MSV_PROMISE_ARGS1
 - MSV_PROMISE_ARGS2
 - MSV_PROMISE_ARGS3
 - MSV_PROMISE_ARGS4
 - MSV_PROMISE_ARGS5
 - MSV_PROMISE_VOID - this macro ignores returned error. Void functions can be called with it too.

The number at the end of macro name is a number of defined arguments (up to five). 
**Examples:**
~~~cpp
MSV_PROMISE(FunctionCall(), LOG_ERROR("Promise failed."));

//generates:
{
	MSV_PROMISE_LIKE_ERRORCODE_TYPE mplsErrorCode = MSV_PROMISE_LIKE_ERRORCODE_NOERROR;
	do
	{
		if (MSV_PROMISE_LIKE_FAILED((mplsErrorCode = (FunctionCall())))
		{
			LOG_ERROR("Promise failed.");
			break;
		}

//---------------------------------------------------

MSV_PROMISE_ARGS2(int x = 1, int y = 2, FunctionCall(x, &y), LOG_ERROR("Promise failed."));

//generates:
{
	MSV_PROMISE_LIKE_ERRORCODE_TYPE mplsErrorCode = MSV_PROMISE_LIKE_ERRORCODE_NOERROR;
	do
	{
		int x = 1;
		int y = 2;
		if (MSV_PROMISE_LIKE_FAILED((mplsErrorCode = (FunctionCall(x, &y))))
		{
			LOG_ERROR("Promise failed.");
			break;
		}
~~~

## MSV_PROMISE_THEN and MSV_PROMISE_THEN_ARGS[n]
Executes call and checks its result. If the call failes it breaks, executes request action or actions (can be any number of actions) and [MSV_PROMISE_CATCH](#MSV_PROMISE_CATCH) is executed. No next checked call is executed.  
There are these versions of MSV_PROMISE_THEN and MSV_PROMISE_THEN_ARGS[n] macros:

 - MSV_PROMISE_THEN
 - MSV_PROMISE_THEN_ARGS1
 - MSV_PROMISE_THEN_ARGS2
 - MSV_PROMISE_THEN_ARGS3
 - MSV_PROMISE_THEN_ARGS4
 - MSV_PROMISE_THEN_ARGS5
 - MSV_PROMISE_THEN_VOID - this macro ignores returned error. Void functions can be called with it too.

The number at the end of macro name is a number of defined arguments (up to five). If you need more arguments you are free to use [MSV_PROMISE_DEFINE_ARGS[n]](#MSV_PROMISE_DEFINE_ARGS[n]) before these macros.
**Examples:**
~~~cpp
MSV_PROMISE_THEN(FunctionCall(), LOG_ERROR("Promise failed."));

//generates:
if (MSV_PROMISE_LIKE_FAILED((mplsErrorCode = (FunctionCall())))
{
	LOG_ERROR("Promise failed.");
	break;
}

//---------------------------------------------------

MSV_PROMISE_THEN_ARGS2(int x = 1, int y = 2, FunctionCall(x, &y), LOG_ERROR("Promise failed."));

//generates:
int x = 1;
int y = 2;
if (MSV_PROMISE_LIKE_FAILED((mplsErrorCode = (FunctionCall(x, &y))))
{
	LOG_ERROR("Promise failed.");
	break;
}
~~~

## MSV_PROMISE_THEN_CONTINUE and MSV_PROMISE_THEN_CONTINUE_ARGS[n]
Executes call and checks its result, but does not break next exectution. If the call failes it executes request action or actions (can be any number of actions) and continues to next call. [MSV_PROMISE_CATCH](#MSV_PROMISE_CATCH) is not executed.  
There are these versions of MSV_PROMISE_THEN_CONTINUE and MSV_PROMISE_THEN_CONTINUE_ARGS[n] macros:

 - MSV_PROMISE_THEN_CONTINUE
 - MSV_PROMISE_THEN_CONTINUE_ARGS1
 - MSV_PROMISE_THEN_CONTINUE_ARGS2
 - MSV_PROMISE_THEN_CONTINUE_ARGS3
 - MSV_PROMISE_THEN_CONTINUE_ARGS4
 - MSV_PROMISE_THEN_CONTINUE_ARGS5

The number at the end of macro name is a number of defined arguments (up to five). If you need more arguments you are free to use [MSV_PROMISE_DEFINE_ARGS[n]](#MSV_PROMISE_DEFINE_ARGS[n]) before these macros.
**Examples:**
~~~cpp
MSV_PROMISE_THEN_CONTINUE(FunctionCall(), LOG_ERROR("Promise failed."));

//generates:
if (MSV_PROMISE_LIKE_FAILED((mplsErrorCode = (FunctionCall())))
{
	LOG_ERROR("Promise failed.");
	mplsErrorCode = MSV_PROMISE_LIKE_ERRORCODE_NOERROR;
}

//---------------------------------------------------

MSV_PROMISE_THEN_CONTINUE_ARGS2(int x = 1, int y = 2, FunctionCall(x, &y), LOG_ERROR("Promise failed."));

//generates:
int x = 1;
int y = 2;
if (MSV_PROMISE_LIKE_FAILED((mplsErrorCode = (FunctionCall(x, &y))))
{
	LOG_ERROR("Promise failed.");
	mplsErrorCode = MSV_PROMISE_LIKE_ERRORCODE_NOERROR;
}
~~~

## MSV_PROMISE_CATCH
End of a promise. If any of checked calls fails it is executed and request action or actions (can be any number of actions) are executed.  
There are these versions of MSV_PROMISE_CATCH macros:

 - MSV_PROMISE_CATCH
 - MSV_PROMISE_CATCH_RETURN_FAILED - returns error code when all requested actions are called.
 - MSV_PROMISE_CATCH_STORE_ERROR - stores error code and executes all requested actions.
 - MSV_PROMISE_CATCH_IGNORE_ERROR - ignores all errors (just ends a promise).

**Examples:**
~~~cpp
MSV_PROMISE_CATCH(LOG_ERROR("Promise failed."));

//generates:
	} while (false);
	if (MSV_PROMISE_LIKE_FAILED(mplsErrorCode))
	{
		LOG_ERROR("Promise failed.");
	}
}

//---------------------------------------------------

MSV_PROMISE_CATCH_RETURN_FAILED(LOG_ERROR("Promise failed."), LOG_ERROR("Promise failed."));

//generates:
	} while (false);
	if (MSV_PROMISE_LIKE_FAILED(mplsErrorCode))
	{
		LOG_ERROR("Promise failed.");
		LOG_ERROR("Promise failed.");
		return mplsErrorCode;
	}
}

//---------------------------------------------------

MSV_PROMISE_LIKE_ERRORCODE_TYPE errorCode;
MSV_PROMISE_CATCH_STORE_ERROR(errorCode, LOG_ERROR("Promise failed."));

//generates:
	} while (false);
	if (MSV_PROMISE_LIKE_FAILED(mplsErrorCode))
	{
		errorCode = mplsErrorCode;
		LOG_ERROR("Promise failed.");
	}
}

//---------------------------------------------------

MSV_PROMISE_CATCH_IGNORE_ERROR

//generates:
	} while (false);
}
~~~

## Source code documentation
You can find generated source code documentation at [https://www.marstech.cz/projects/mpls/1.0.1/doc](https://www.marstech.cz/projects/mpls/1.0.1/doc){:target="_blank"}.

## License
This project is released under GNU General Public License version 3. If you can not or do not want to accept GNU GPLv3 license and you would like to use this project under another license, please contact me on [info@marstech.cz](mailto:info@marstech.cz) or visit [www.marstech.cz](https://www.marstech.cz/en).