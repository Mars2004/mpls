#pragma once

#include "../mpls.h"

#include <gmock/gmock.h>


class ImplsTesting
{
public:
	virtual ~ImplsTesting() {  }

	virtual void TestVoidMethod() = 0;
	virtual MSV_PROMISE_LIKE_ERRORCODE_TYPE TestMethod() = 0;
	virtual MSV_PROMISE_LIKE_ERRORCODE_TYPE TestMethod(int arg1) = 0;
	virtual MSV_PROMISE_LIKE_ERRORCODE_TYPE TestMethod(int arg1, int arg2) = 0;
	virtual MSV_PROMISE_LIKE_ERRORCODE_TYPE TestMethod(int arg1, int arg2, int arg3) = 0;
	virtual MSV_PROMISE_LIKE_ERRORCODE_TYPE TestMethod(int arg1, int arg2, int arg3, int arg4) = 0;
	virtual MSV_PROMISE_LIKE_ERRORCODE_TYPE TestMethod(int arg1, int arg2, int arg3, int arg4, int arg5) = 0;
	virtual MSV_PROMISE_LIKE_ERRORCODE_TYPE TestMethod(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6) = 0;
};

class MplsTesting :
	public ImplsTesting
{
public:
	MOCK_METHOD0(TestVoidMethod, void());
	MOCK_METHOD0(TestMethod, MSV_PROMISE_LIKE_ERRORCODE_TYPE());
	MOCK_METHOD1(TestMethod, MSV_PROMISE_LIKE_ERRORCODE_TYPE(int arg1));
	MOCK_METHOD2(TestMethod, MSV_PROMISE_LIKE_ERRORCODE_TYPE(int arg1, int arg2));
	MOCK_METHOD3(TestMethod, MSV_PROMISE_LIKE_ERRORCODE_TYPE(int arg1, int arg2, int arg3));
	MOCK_METHOD4(TestMethod, MSV_PROMISE_LIKE_ERRORCODE_TYPE(int arg1, int arg2, int arg3, int arg4));
	MOCK_METHOD5(TestMethod, MSV_PROMISE_LIKE_ERRORCODE_TYPE(int arg1, int arg2, int arg3, int arg4, int arg5));
	MOCK_METHOD6(TestMethod, MSV_PROMISE_LIKE_ERRORCODE_TYPE(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6));
};

class ImplsFixture:
	public ::testing::Test
{
protected:
	int TestCatchAndReturnFailed()
	{
		MSV_PROMISE(m_mplsTesting.TestMethod(1))
		MSV_PROMISE_CATCH_RETURN_FAILED()
		return -1;
	}

	MplsTesting m_mplsTesting;
};
