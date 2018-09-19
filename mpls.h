/**************************************************************************************************//**
* @defgroup		MPLS MarsTech Promise Like Syntax
* @brief			MarsTech Promise Like Syntax
* @details		Contains implementation and all definitions of MarsTech Promise Like Syntax.
* @copyright	GNU General Public License (GPLv3).
* @{
******************************************************************************************************/

/**************************************************************************************************//**
* @file		
* @brief			MarsTech Promise Like Syntax
* @details		Contains implementation and all definitions of MarsTech Promise Like Syntax.
* @author		Martin Svoboda
* @date			06.07.2018
* @copyright	GNU General Public License (GPLv3).
******************************************************************************************************/


/*
This file is part of MarsTech Promise Like Syntax.

MarsTech Promise Like Syntax is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

MarsTech Promise Like Syntax is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Foobar. If not, see <https://www.gnu.org/licenses/>.
*/


#ifndef MARSTECH_PROMISE_LIKE_SYNTAX
#define MARSTECH_PROMISE_LIKE_SYNTAX


#ifndef MSV_PROMISE_LIKE_ERRORCODE_TYPE
#include <cstdint>
/**************************************************************************************************//**
* @def			MSV_PROMISE_LIKE_ERRORCODE_TYPE	
* @brief			MPLS error  code type
* @details		Defines errorcode type for handling errors by MPLS.
* @note			Anyone can define its own errorcode type by defining this macro before including
*					this header file.
******************************************************************************************************/
#define MSV_PROMISE_LIKE_ERRORCODE_TYPE int32_t
#endif // !MSV_PROMISE_LIKE_ERRORCODE_TYPE

#ifndef MSV_PROMISE_LIKE_ERRORCODE_NOERROR
#include <cstdint>
/**************************************************************************************************//**
* @def			MSV_PROMISE_LIKE_ERRORCODE_NOERROR	
* @brief			MPLS no error errorcode value
* @details		Defines no error value for errorcode handled by MPLS.
* @note			Anyone can define its own errorcode type by defining this macro before including
*					this header file.
******************************************************************************************************/
#define MSV_PROMISE_LIKE_ERRORCODE_NOERROR 0
#endif // !MSV_PROMISE_LIKE_ERRORCODE_NOERROR

#ifndef MSV_PROMISE_LIKE_FAILED
/**************************************************************************************************//**
* @def			MSV_PROMISE_LIKE_FAILED(errorCode)	
* @brief			MPLS check if FAILED
* @details		Defines evaluating FAILURE errorcodes by MPLS.
* @param[in]	errorcode	Errorcode to check if failed or not.
* @note			Anyone can define its own errorcode type by defining this macro before including
*					this header file.
* @see			MSV_PROMISE_LIKE_ERRORCODE_NOERROR
******************************************************************************************************/
#define MSV_PROMISE_LIKE_FAILED(errorcode) ((errorcode) != MSV_PROMISE_LIKE_ERRORCODE_NOERROR)
#endif // !MSV_PROMISE_LIKE_FAILED


/******************************************************************************************************
*									MARSTECH PROMISE LIKE ARGUMENT DEFINITIONS
******************************************************************************************************/


/**************************************************************************************************//**
* @def			MSV_PROMISE_DEFINE_ARGS1(mplsArg1)
* @brief			Define one output argument
* @details		Defines one output argument for next @ref MSV_PROMISE_THEN. Argument can be used anytime
*					later, but must be used before @ref MSV_PROMISE_CATCH macros.
* @param[in]	mplsArg1		The first defined argument/variable/etc. It can also be initialized.
* @warning		Argument defined by this macro will be visible only in @ref MSV_PROMISE_THEN macros.
*					They won't be visible after @ref MSV_PROMISE_CATCH macros even in them.
******************************************************************************************************/
#define MSV_PROMISE_DEFINE_ARGS1(mplsArg1) \
	mplsArg1;

/**************************************************************************************************//**
* @def			MSV_PROMISE_DEFINE_ARGS2(mplsArg1, mplsArg2)
* @brief			Define two output arguments
* @details		Defines two output arguments for next @ref MSV_PROMISE_THEN. Arguments can be used anytime
*					later, but must be used before @ref MSV_PROMISE_CATCH macros.
* @param[in]	mplsArg1		The first defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg2		The second defined argument/variable/etc. It can also be initialized.
* @warning		Arguments defined by this macro will be visible only in @ref MSV_PROMISE_THEN macros.
*					They won't be visible after @ref MSV_PROMISE_CATCH macros even in them.
******************************************************************************************************/
#define MSV_PROMISE_DEFINE_ARGS2(mplsArg1, mplsArg2) \
	MSV_PROMISE_DEFINE_ARGS1(mplsArg1) \
	mplsArg2;

/**************************************************************************************************//**
* @def			MSV_PROMISE_DEFINE_ARGS3(mplsArg1, mplsArg2, mplsArg3)
* @brief			Define three output arguments
* @details		Defines three output arguments for next @ref MSV_PROMISE_THEN. Arguments can be used anytime
*					later, but must be used before @ref MSV_PROMISE_CATCH macros.
* @param[in]	mplsArg1		The first defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg2		The second defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg3		The third defined argument/variable/etc. It can also be initialized.
* @warning		Arguments defined by this macro will be visible only in @ref MSV_PROMISE_THEN macros.
*					They won't be visible after @ref MSV_PROMISE_CATCH macros even in them.
******************************************************************************************************/
#define MSV_PROMISE_DEFINE_ARGS3(mplsArg1, mplsArg2, mplsArg3) \
	MSV_PROMISE_DEFINE_ARGS2(mplsArg1, mplsArg2) \
	mplsArg3;

/**************************************************************************************************//**
* @def			MSV_PROMISE_DEFINE_ARGS4(mplsArg1, mplsArg2, mplsArg3, mplsArg4)
* @brief			Define four output arguments
* @details		Defines four output arguments for next @ref MSV_PROMISE_THEN. Arguments can be used anytime
*					later, but must be used before @ref MSV_PROMISE_CATCH macros.
* @param[in]	mplsArg1		The first defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg2		The second defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg3		The third defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg4		The fourth defined argument/variable/etc. It can also be initialized.
* @warning		Arguments defined by this macro will be visible only in @ref MSV_PROMISE_THEN macros.
*					They won't be visible after @ref MSV_PROMISE_CATCH macros even in them.
******************************************************************************************************/
#define MSV_PROMISE_DEFINE_ARGS4(mplsArg1, mplsArg2, mplsArg3, mplsArg4) \
	MSV_PROMISE_DEFINE_ARGS3(mplsArg1, mplsArg2, mplsArg3) \
	mplsArg4;

/**************************************************************************************************//**
* @def			MSV_PROMISE_DEFINE_ARGS5(mplsArg1, mplsArg2, mplsArg3, mplsArg4, mplsArg5)
* @brief			Define five output arguments
* @details		Defines five output arguments for next @ref MSV_PROMISE_THEN. Arguments can be used anytime
*					later, but must be used before @ref MSV_PROMISE_CATCH macros.
* @param[in]	mplsArg1		The first defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg2		The second defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg3		The third defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg4		The fourth defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg5		The fifth defined argument/variable/etc. It can also be initialized.
* @warning		Arguments defined by this macro will be visible only in @ref MSV_PROMISE_THEN macros.
*					They won't be visible after @ref MSV_PROMISE_CATCH macros even in them.
* @note			If you need define more arguments, you can use MSV_PROMISE_DEFINE_ARGSx many times.
******************************************************************************************************/
#define MSV_PROMISE_DEFINE_ARGS5(mplsArg1, mplsArg2, mplsArg3, mplsArg4, mplsArg5) \
	MSV_PROMISE_DEFINE_ARGS4(mplsArg1, mplsArg2, mplsArg3, mplsArg4) \
	mplsArg5;


/******************************************************************************************************
*											MARSTECH PROMISE LIKE THENS
******************************************************************************************************/


/**************************************************************************************************//**
* @def			MSV_PROMISE_THEN(mplsThen, ...)
* @brief			Execute and check next
* @details		Executes next function call. It also checks if
*					execution failed or not. Requested actions are executed when function/method returns error.
* @param[in]	mplsThen		The next function/method call (it is called only if all previous calls succeded).
*									All arguments (it is variadic macro) after this one are actions which
*									will be executed when call failed (logging, setting default values, etc.). 
* @warning		Arguments defined by this macro will be visible only in @ref MSV_PROMISE_THEN macros.
*					They won't be visible after @ref MSV_PROMISE_CATCH macros even in them.
* @note			If you need define more arguments, you can use MSV_PROMISE_DEFINE_ARGSx many time.
******************************************************************************************************/
#define MSV_PROMISE_THEN(mplsThen, ...) \
	if (MSV_PROMISE_LIKE_FAILED((mplsErrorcode = (mplsThen)))) \
	{ \
		__VA_ARGS__; \
		break; \
	}

/**************************************************************************************************//**
* @def			MSV_PROMISE_THEN_ARGS1(mplsArg1, mplsThen, ...)
* @brief			Define arguments and execute and check next
* @details		Defines one output argument for next function execution and executes it. It also checks if
*					execution failed or not. Requested actions are executed when function/method returns error.
* @param[in]	mplsArg1		The first defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsThen		The next function/method call (it is called only if all previous calls succeded).
*									All arguments (it is variadic macro) after this one are actions which
*									will be executed when call failed (logging, setting default values, etc.). 
* @warning		Arguments defined by this macro will be visible only in @ref MSV_PROMISE_THEN macros.
*					They won't be visible after @ref MSV_PROMISE_CATCH macros even in them.
* @note			If you need define more arguments, you can use MSV_PROMISE_DEFINE_ARGSx many time.
* @see			MSV_PROMISE_DEFINE_ARGS5
******************************************************************************************************/
#define MSV_PROMISE_THEN_ARGS1(mplsArg1, mplsThen, ...) \
	mplsArg1; \
	MSV_PROMISE_THEN(mplsThen, __VA_ARGS__)

/**************************************************************************************************//**
* @def			MSV_PROMISE_THEN_ARGS2(mplsArg1, mplsArg2, mplsThen, ...)
* @brief			Define arguments and execute and check next
* @details		Defines two output arguments for next function execution and executes it. It also checks if
*					execution failed or not. Requested actions are executed when function/method returns error.
* @param[in]	mplsArg1		The first defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg2		The second defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsThen		The next function/method call (it is called only if all previous calls succeded).
*									All arguments (it is variadic macro) after this one are actions which
*									will be executed when call failed (logging, setting default values, etc.). 
* @warning		Arguments defined by this macro will be visible only in @ref MSV_PROMISE_THEN macros.
*					They won't be visible after @ref MSV_PROMISE_CATCH macros even in them.
* @note			If you need define more arguments, you can use MSV_PROMISE_DEFINE_ARGSx many time.
* @see			MSV_PROMISE_DEFINE_ARGS5
******************************************************************************************************/
#define MSV_PROMISE_THEN_ARGS2(mplsArg1, mplsArg2, mplsThen, ...) \
	mplsArg2; \
	MSV_PROMISE_THEN_ARGS1(mplsArg1, mplsThen, __VA_ARGS__)

/**************************************************************************************************//**
* @def			MSV_PROMISE_THEN_ARGS3(mplsArg1, mplsArg2, mplsArg3, mplsThen, ...)
* @brief			Define arguments and execute and check next
* @details		Defines three output arguments for next function execution and executes it. It also checks if
*					execution failed or not. Requested actions are executed when function/method returns error.
* @param[in]	mplsArg1		The first defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg2		The second defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg3		The third defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsThen		The next function/method call (it is called only if all previous calls succeded).
*									All arguments (it is variadic macro) after this one are actions which
*									will be executed when call failed (logging, setting default values, etc.). 
* @warning		Arguments defined by this macro will be visible only in @ref MSV_PROMISE_THEN macros.
*					They won't be visible after @ref MSV_PROMISE_CATCH macros even in them.
* @note			If you need define more arguments, you can use MSV_PROMISE_DEFINE_ARGSx many time.
* @see			MSV_PROMISE_DEFINE_ARGS5
******************************************************************************************************/
#define MSV_PROMISE_THEN_ARGS3(mplsArg1, mplsArg2, mplsArg3, mplsThen, ...) \
	mplsArg3; \
	MSV_PROMISE_THEN_ARGS2(mplsArg1, mplsArg2, mplsThen, __VA_ARGS__)

/**************************************************************************************************//**
* @def			MSV_PROMISE_THEN_ARGS4(mplsArg1, mplsArg2, mplsArg3, mplsArg4, mplsThen, ...)
* @brief			Define arguments and execute and check next
* @details		Defines four output arguments for next function execution and executes it. It also checks if
*					execution failed or not. Requested actions are executed when function/method returns error.
* @param[in]	mplsArg1		The first defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg2		The second defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg3		The third defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg4		The fourth defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsThen		The next function/method call (it is called only if all previous calls succeded).
*									All arguments (it is variadic macro) after this one are actions which
*									will be executed when call failed (logging, setting default values, etc.). 
* @warning		Arguments defined by this macro will be visible only in @ref MSV_PROMISE_THEN macros.
*					They won't be visible after @ref MSV_PROMISE_CATCH macros even in them.
* @note			If you need define more arguments, you can use MSV_PROMISE_DEFINE_ARGSx many time.
* @see			MSV_PROMISE_DEFINE_ARGS5
******************************************************************************************************/
#define MSV_PROMISE_THEN_ARGS4(mplsArg1, mplsArg2, mplsArg3, mplsArg4, mplsThen, ...) \
	mplsArg4; \
	MSV_PROMISE_THEN_ARGS3(mplsArg1, mplsArg2, mplsArg3, mplsThen, __VA_ARGS__)

/**************************************************************************************************//**
* @def			MSV_PROMISE_THEN_ARGS5(mplsArg1, mplsArg2, mplsArg3, mplsArg4, mplsArg5, mplsThen, ...)
* @brief			Define arguments and execute and check next
* @details		Defines five output arguments for next function execution and executes it. It also checks if
*					execution failed or not. Requested actions are executed when function/method returns error.
* @param[in]	mplsArg1		The first defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg2		The second defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg3		The third defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg4		The fourth defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg5		The fifth defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsThen		The next function/method call (it is called only if all previous calls succeded).
*									All arguments (it is variadic macro) after this one are actions which
*									will be executed when call failed (logging, setting default values, etc.). 
* @warning		Arguments defined by this macro will be visible only in @ref MSV_PROMISE_THEN macros.
*					They won't be visible after @ref MSV_PROMISE_CATCH macros even in them.
* @note			If you need define more arguments, you can use MSV_PROMISE_DEFINE_ARGSx many time.
* @see			MSV_PROMISE_DEFINE_ARGS5
******************************************************************************************************/
#define MSV_PROMISE_THEN_ARGS5(mplsArg1, mplsArg2, mplsArg3, mplsArg4, mplsArg5, mplsThen, ...) \
	mplsArg5; \
	MSV_PROMISE_THEN_ARGS4(mplsArg1, mplsArg2, mplsArg3, mplsArg4, mplsThen, __VA_ARGS__)

/**************************************************************************************************//**
* @def			MSV_PROMISE_THEN_CONTINUE(mplsThen, ...)
* @brief			Execute and check next
* @details		Execute next step and checks if execution failed or not. Requested actions are executed
*					when function/method returns error.
*					It will continue execution to next step - it does not break and does not end in catch.
* @param[in]	mplsThen		The next function/method call (it is called only if all previous calls succeded).
*									All arguments (it is variadic macro) after this one are actions which
*									will be executed when call failed (logging, setting default values, etc.). 
* @warning		Arguments defined by this macro will be visible only in @ref MSV_PROMISE_THEN macros.
*					They won't be visible after @ref MSV_PROMISE_CATCH macros even in them.
* @note			If you need define more arguments, you can use MSV_PROMISE_DEFINE_ARGSx many time.
* @see			MSV_PROMISE_DEFINE_ARGS5
******************************************************************************************************/
#define MSV_PROMISE_THEN_CONTINUE(mplsThen, ...) \
	if (MSV_PROMISE_LIKE_FAILED((mplsErrorcode = (mplsThen)))) \
	{ \
		__VA_ARGS__; \
		mplsErrorcode = MSV_PROMISE_LIKE_ERRORCODE_NOERROR; \
	}

/**************************************************************************************************//**
* @def			MSV_PROMISE_THEN_CONTINUE_ARGS1(mplsArg1, mplsThen, ...)
* @brief			Define arguments and execute and check next
* @details		Defines one output argument for next function execution and executes it. It also checks if
*					execution failed or not. Requested actions are executed when function/method returns error.
*					It will continue execution to next step - it does not break and does not end in catch.
* @param[in]	mplsArg1		The first defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsThen		The next function/method call (it is called only if all previous calls succeded).
*									All arguments (it is variadic macro) after this one are actions which
*									will be executed when call failed (logging, setting default values, etc.). 
* @warning		Arguments defined by this macro will be visible only in @ref MSV_PROMISE_THEN macros.
*					They won't be visible after @ref MSV_PROMISE_CATCH macros even in them.
* @note			If you need define more arguments, you can use MSV_PROMISE_DEFINE_ARGSx many time.
* @see			MSV_PROMISE_DEFINE_ARGS5
******************************************************************************************************/
#define MSV_PROMISE_THEN_CONTINUE_ARGS1(mplsArg1, mplsThen, ...) \
	mplsArg1; \
	MSV_PROMISE_THEN_CONTINUE(mplsThen, __VA_ARGS__)

/**************************************************************************************************//**
* @def			MSV_PROMISE_THEN_CONTINUE_ARGS2(mplsArg1, mplsArg2, mplsThen, ...)
* @brief			Define arguments and execute and check next
* @details		Defines two output arguments for next function execution and executes it. It also checks if
*					execution failed or not. Requested actions are executed when function/method returns error.
*					It will continue execution to next step - it does not break and does not end in catch.
* @param[in]	mplsArg1		The first defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg2		The second defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsThen		The next function/method call (it is called only if all previous calls succeded).
*									All arguments (it is variadic macro) after this one are actions which
*									will be executed when call failed (logging, setting default values, etc.). 
* @warning		Arguments defined by this macro will be visible only in @ref MSV_PROMISE_THEN macros.
*					They won't be visible after @ref MSV_PROMISE_CATCH macros even in them.
* @note			If you need define more arguments, you can use MSV_PROMISE_DEFINE_ARGSx many time.
* @see			MSV_PROMISE_DEFINE_ARGS5
******************************************************************************************************/
#define MSV_PROMISE_THEN_CONTINUE_ARGS2(mplsArg1, mplsArg2, mplsThen, ...) \
	mplsArg2; \
	MSV_PROMISE_THEN_CONTINUE_ARGS1(mplsArg1, mplsThen, __VA_ARGS__)

/**************************************************************************************************//**
* @def			MSV_PROMISE_THEN_CONTINUE_ARGS3(mplsArg1, mplsArg2, mplsArg3, mplsThen, ...)
* @brief			Define arguments and execute and check next
* @details		Defines three output arguments for next function execution and executes it. It also checks if
*					execution failed or not. Requested actions are executed when function/method returns error.
*					It will continue execution to next step - it does not break and does not end in catch.
* @param[in]	mplsArg1		The first defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg2		The second defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg3		The third defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsThen		The next function/method call (it is called only if all previous calls succeded).
*									All arguments (it is variadic macro) after this one are actions which
*									will be executed when call failed (logging, setting default values, etc.). 
* @warning		Arguments defined by this macro will be visible only in @ref MSV_PROMISE_THEN macros.
*					They won't be visible after @ref MSV_PROMISE_CATCH macros even in them.
* @note			If you need define more arguments, you can use MSV_PROMISE_DEFINE_ARGSx many time.
* @see			MSV_PROMISE_DEFINE_ARGS5
******************************************************************************************************/
#define MSV_PROMISE_THEN_CONTINUE_ARGS3(mplsArg1, mplsArg2, mplsArg3, mplsThen, ...) \
	mplsArg3; \
	MSV_PROMISE_THEN_CONTINUE_ARGS2(mplsArg1, mplsArg2, mplsThen, __VA_ARGS__)

/**************************************************************************************************//**
* @def			MSV_PROMISE_THEN_CONTINUE_ARGS4(mplsArg1, mplsArg2, mplsArg3, mplsArg4, mplsThen, ...)
* @brief			Define arguments and execute and check next
* @details		Defines four output arguments for next function execution and executes it. It also checks if
*					execution failed or not. Requested actions are executed when function/method returns error.
*					It will continue execution to next step - it does not break and does not end in catch.
* @param[in]	mplsArg1		The first defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg2		The second defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg3		The third defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg4		The fourth defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsThen		The next function/method call (it is called only if all previous calls succeded).
*									All arguments (it is variadic macro) after this one are actions which
*									will be executed when call failed (logging, setting default values, etc.). 
* @warning		Arguments defined by this macro will be visible only in @ref MSV_PROMISE_THEN macros.
*					They won't be visible after @ref MSV_PROMISE_CATCH macros even in them.
* @note			If you need define more arguments, you can use MSV_PROMISE_DEFINE_ARGSx many time.
* @see			MSV_PROMISE_DEFINE_ARGS5
******************************************************************************************************/
#define MSV_PROMISE_THEN_CONTINUE_ARGS4(mplsArg1, mplsArg2, mplsArg3, mplsArg4, mplsThen, ...) \
	mplsArg4; \
	MSV_PROMISE_THEN_CONTINUE_ARGS3(mplsArg1, mplsArg2, mplsArg3, mplsThen, __VA_ARGS__)

/**************************************************************************************************//**
* @def			MSV_PROMISE_THEN_CONTINUE_ARGS5(mplsArg1, mplsArg2, mplsArg3, mplsArg4, mplsArg5, mplsThen, ...)
* @brief			Define arguments and execute and check next
* @details		Defines five output arguments for next function execution and executes it. It also checks if
*					execution failed or not. Requested actions are executed when function/method returns error.
*					It will continue execution to next step - it does not break and does not end in catch.
* @param[in]	mplsArg1		The first defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg2		The second defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg3		The third defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg4		The fourth defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg5		The fifth defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsThen		The next function/method call (it is called only if all previous calls succeded).
*									All arguments (it is variadic macro) after this one are actions which
*									will be executed when call failed (logging, setting default values, etc.). 
* @warning		Arguments defined by this macro will be visible only in @ref MSV_PROMISE_THEN macros.
*					They won't be visible after @ref MSV_PROMISE_CATCH macros even in them.
* @note			If you need define more arguments, you can use MSV_PROMISE_DEFINE_ARGSx many time.
* @see			MSV_PROMISE_DEFINE_ARGS5
******************************************************************************************************/
#define MSV_PROMISE_THEN_CONTINUE_ARGS5(mplsArg1, mplsArg2, mplsArg3, mplsArg4, mplsArg5, mplsThen, ...) \
	mplsArg5; \
	MSV_PROMISE_THEN_CONTINUE_ARGS4(mplsArg1, mplsArg2, mplsArg3, mplsArg4, mplsThen, __VA_ARGS__)


/**************************************************************************************************//**
* @def			MSV_PROMISE_THEN_VOID(mplsThen)	
* @brief			MPLS void function
* @details		Defines execution of void returning function/method (it just call it without any checks).
* @param[in]	mplsThen		Checked action (it is called and its result/errorcode is checked).
* @note			This macro does not have ARGSx variants - if you need to define some arguments you can
*					use any of MSV_PROMISE_DEFINE_ARGSx macros.
******************************************************************************************************/
#define MSV_PROMISE_THEN_VOID(mplsThen) \
	mplsThen;


/******************************************************************************************************
*											MARSTECH PROMISE LIKE PROMISES
******************************************************************************************************/


/**************************************************************************************************//**
* @def			MSV_PROMISE_INNER_START
* @brief			Inner code of MSV_PROMISE macros.
* @details		Creates promise start (defines inner errorcode and creates start of do-while) and executes
*					the first step. 
* @warning		Do not use this macro standalone. It is used as part of MSV_PROMISE_CATCH macros.
******************************************************************************************************/
#define MSV_PROMISE_INNER_START \
{ \
	MSV_PROMISE_LIKE_ERRORCODE_TYPE mplsErrorcode = MSV_PROMISE_LIKE_ERRORCODE_NOERROR; \
	do \
	{ \

/**************************************************************************************************//**
* @def			MSV_PROMISE(promiseLike, ...)
* @brief			Promise entry point
* @details		The first function execution and checks if execution failed or not.
*					Requested actions are executed when function/method returns error.
* @param[in]	promiseLike	The first function/method call.
*									All arguments (it is variadic macro) after this one are actions which
*									will be executed when call failed (logging, setting default values, etc.). 
* @warning		Arguments defined by this macro will be visible only in @ref MSV_PROMISE_THEN macros.
*					They won't be visible after @ref MSV_PROMISE_CATCH macros even in them.
******************************************************************************************************/
#define MSV_PROMISE(promiseLike, ...) \
	MSV_PROMISE_INNER_START \
	MSV_PROMISE_THEN(promiseLike, __VA_ARGS__)

/**************************************************************************************************//**
* @def			MSV_PROMISE_ARGS1(mplsArg1, promiseLike, ...)
* @brief			Promise entry point
* @details		Defines one output argument for the first function execution and executes it. It also checks if
*					execution failed or not. Requested actions are executed when function/method returns error.
* @param[in]	mplsArg1		The first defined argument/variable/etc. It can also be initialized.
* @param[in]	promiseLike	The first function/method call.
*									All arguments (it is variadic macro) after this one are actions which
*									will be executed when call failed (logging, setting default values, etc.). 
* @warning		Arguments defined by this macro will be visible only in @ref MSV_PROMISE_THEN macros.
*					They won't be visible after @ref MSV_PROMISE_CATCH macros even in them.
******************************************************************************************************/
#define MSV_PROMISE_ARGS1(mplsArg1, promiseLike, ...) \
	MSV_PROMISE_INNER_START \
	MSV_PROMISE_THEN_ARGS1(mplsArg1, promiseLike, __VA_ARGS__)

/**************************************************************************************************//**
* @def			MSV_PROMISE_ARGS2(mplsArg1, mplsArg2, promiseLike, ...)
* @brief			Promise entry point
* @details		Defines two output arguments for the first function execution and executes it. It also checks if
*					execution failed or not. Requested actions are executed when function/method returns error.
* @param[in]	mplsArg1		The first defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg2		The second defined argument/variable/etc. It can also be initialized.
* @param[in]	promiseLike	The first function/method call.
*									All arguments (it is variadic macro) after this one are actions which
*									will be executed when call failed (logging, setting default values, etc.). 
* @warning		Arguments defined by this macro will be visible only in @ref MSV_PROMISE_THEN macros.
*					They won't be visible after @ref MSV_PROMISE_CATCH macros even in them.
******************************************************************************************************/
#define MSV_PROMISE_ARGS2(mplsArg1, mplsArg2, promiseLike, ...) \
	MSV_PROMISE_INNER_START \
	MSV_PROMISE_THEN_ARGS2(mplsArg1, mplsArg2, promiseLike, __VA_ARGS__)

/**************************************************************************************************//**
* @def			MSV_PROMISE_ARGS3(mplsArg1, mplsArg2, mplsArg3, promiseLike, ...)
* @brief			Promise entry point
* @details		Defines three output arguments for the first function execution and executes it. It also checks if
*					execution failed or not. Requested actions are executed when function/method returns error.
* @param[in]	mplsArg1		The first defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg2		The second defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg3		The third defined argument/variable/etc. It can also be initialized.
* @param[in]	promiseLike	The first function/method call.
*									All arguments (it is variadic macro) after this one are actions which
*									will be executed when call failed (logging, setting default values, etc.). 
* @warning		Arguments defined by this macro will be visible only in @ref MSV_PROMISE_THEN macros.
*					They won't be visible after @ref MSV_PROMISE_CATCH macros even in them.
******************************************************************************************************/
#define MSV_PROMISE_ARGS3(mplsArg1, mplsArg2, mplsArg3, promiseLike, ...) \
	MSV_PROMISE_INNER_START \
	MSV_PROMISE_THEN_ARGS3(mplsArg1, mplsArg2, mplsArg3, promiseLike, __VA_ARGS__)

/**************************************************************************************************//**
* @def			MSV_PROMISE_ARGS4(mplsArg1, mplsArg2, mplsArg3, mplsArg4, promiseLike, ...)
* @brief			Promise entry point
* @details		Defines four output arguments for the first function execution and executes it. It also checks if
*					execution failed or not. Requested actions are executed when function/method returns error.
* @param[in]	mplsArg1		The first defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg2		The second defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg3		The third defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg4		The fourth defined argument/variable/etc. It can also be initialized.
* @param[in]	promiseLike	The first function/method call.
*									All arguments (it is variadic macro) after this one are actions which
*									will be executed when call failed (logging, setting default values, etc.). 
* @warning		Arguments defined by this macro will be visible only in @ref MSV_PROMISE_THEN macros.
*					They won't be visible after @ref MSV_PROMISE_CATCH macros even in them.
******************************************************************************************************/
#define MSV_PROMISE_ARGS4(mplsArg1, mplsArg2, mplsArg3, mplsArg4, promiseLike, ...) \
	MSV_PROMISE_INNER_START \
	MSV_PROMISE_THEN_ARGS4(mplsArg1, mplsArg2, mplsArg3, mplsArg4, promiseLike, __VA_ARGS__)

/**************************************************************************************************//**
* @def			MSV_PROMISE_ARGS5(mplsArg1, mplsArg2, mplsArg3, mplsArg4, mplsArg5, promiseLike, ...)
* @brief			Promise entry point
* @details		Defines five output arguments for the first function execution and executes it. It also checks if
*					execution failed or not. Requested actions are executed when function/method returns error.
* @param[in]	mplsArg1		The first defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg2		The second defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg3		The third defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg4		The fourth defined argument/variable/etc. It can also be initialized.
* @param[in]	mplsArg5		The fifth defined argument/variable/etc. It can also be initialized.
* @param[in]	promiseLike	The first function/method call.
*									All arguments (it is variadic macro) after this one are actions which
*									will be executed when call failed (logging, setting default values, etc.). 
* @warning		Arguments defined by this macro will be visible only in @ref MSV_PROMISE_THEN macros.
*					They won't be visible after @ref MSV_PROMISE_CATCH macros even in them.
******************************************************************************************************/
#define MSV_PROMISE_ARGS5(mplsArg1, mplsArg2, mplsArg3, mplsArg4, mplsArg5, promiseLike, ...) \
	MSV_PROMISE_INNER_START \
	MSV_PROMISE_THEN_ARGS5(mplsArg1, mplsArg2, mplsArg3, mplsArg4, mplsArg5, promiseLike, __VA_ARGS__)

/**************************************************************************************************//**
* @def			MSV_PROMISE_VOID(promiseLike)
* @brief			Promise entry point
* @details		Defines execution of void returning function/method (it just call it without any checks)
* @param[in]	promiseLike	The first function/method call.
* @note			This macro does not have ARGSx variants.
******************************************************************************************************/
#define MSV_PROMISE_VOID(promiseLike) \
	MSV_PROMISE_INNER_START \
	MSV_PROMISE_THEN_VOID(promiseLike)


/******************************************************************************************************
*											MARSTECH PROMISE LIKE CATCHES
******************************************************************************************************/


/**************************************************************************************************//**
* @def			MSV_PROMISE_CATCH_INNER_START(...)
* @brief			Inner code of MSV_PROMISE_CATCH macros.
* @details		Defines what to do if error occured and returns errorcode. Actions (logging, returns,
*					assigns, etc.) are expected as macro arguments and will be called before return.
* @warning		Do not use this macro standalone. It is used as part of MSV_PROMISE_CATCH macros.
******************************************************************************************************/
#define MSV_PROMISE_CATCH_INNER_START \
	} while (false); \
	if (MSV_PROMISE_LIKE_FAILED(mplsErrorcode)) \
	{ 

/**************************************************************************************************//**
* @def			MSV_PROMISE_CATCH(...)	
* @brief			MPLS catch block
* @details		Defines what to do if error occured. Actions (logging, returns, assigns, etc.) are
*					expected as macro arguments.
* @warning		Actions are separated by commas. Only last action ends by semicolon.
******************************************************************************************************/
#define MSV_PROMISE_CATCH(...) \
	MSV_PROMISE_CATCH_INNER_START \
		__VA_ARGS__; \
	} \
}

/**************************************************************************************************//**
* @def			MSV_PROMISE_CATCH_RETURN_FAILED(...)
* @brief			MPLS catch block
* @details		Defines what to do if error occured and returns errorcode. Actions (logging, returns,
*					assigns, etc.) are expected as macro arguments and will be called before return.
* @warning		Actions are separated by commas. Only last action ends by semicolon.
******************************************************************************************************/
#define MSV_PROMISE_CATCH_RETURN_FAILED(...) \
	MSV_PROMISE_CATCH_INNER_START \
		__VA_ARGS__; \
		return mplsErrorcode; \
	} \
}

/**************************************************************************************************//**
* @def			MSV_PROMISE_CATCH_STORE_ERROR(mplsStoreErrorcode, ...)
* @brief			MPLS catch block
* @details		Defines what to do if error occured. Actions (logging, returns, assigns, etc.) are
*					expected as macro arguments. Occured errorcode is stored to \p mplsStoreErrorcode
*					before the first action execution.
* @param[out]	mplsStoreErrorcode	Variable to which will be stored errorcode.
* @warning		Actions are separated by commas. Only last action ends by semicolon.
******************************************************************************************************/
#define MSV_PROMISE_CATCH_STORE_ERROR(mplsStoreErrorcode, ...) \
	MSV_PROMISE_CATCH_INNER_START \
		mplsStoreErrorcode = mplsErrorcode; \
		__VA_ARGS__; \
	} \
}

/**************************************************************************************************//**
* @def			MSV_PROMISE_CATCH_IGNORE_ERROR
* @brief			MPLS catch block
* @details		Ends promise without any error checks.
******************************************************************************************************/
#define MSV_PROMISE_CATCH_IGNORE_ERROR \
	} while (false); \
}

#endif // !MARSTECH_PROMISE_LIKE_SYNTAX

/** @} */	//End of group MPLS.
