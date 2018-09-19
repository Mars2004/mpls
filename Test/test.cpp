#include "gtest/gtest.h"

#include "MplsTest.h"


using namespace ::testing;


typedef ImplsFixture MplsTest;


TEST_F(MplsTest, ItShoudntCatchErrorWithoutReason_NOARGS)
{
	EXPECT_CALL(m_mplsTesting, TestMethod())
		.Times(3)
		.WillRepeatedly(Return(0));

	int err1 = 1;
	int err2 = 1;
	int err3 = 1;
	int mplsErrorcodeCheck = 1;

	//test
	MSV_PROMISE(err1 = m_mplsTesting.TestMethod())
	MSV_PROMISE_THEN(err2 = m_mplsTesting.TestMethod())
	MSV_PROMISE_THEN(err3 = m_mplsTesting.TestMethod())
	MSV_PROMISE_CATCH(mplsErrorcodeCheck = mplsErrorcode)

	EXPECT_EQ(err1, 0);
	EXPECT_EQ(err2, 0);
	EXPECT_EQ(err3, 0);
	EXPECT_EQ(mplsErrorcodeCheck, 1);
}

TEST_F(MplsTest, ItShoudntCatchErrorWithoutReason_ARGS1)
{
	EXPECT_CALL(m_mplsTesting, TestMethod(1))
		.Times(3)
		.WillRepeatedly(Return(0));

	int err1 = 1;
	int err2 = 1;
	int err3 = 1;
	int mplsErrorcodeCheck = 1;

	//test
	MSV_PROMISE_ARGS1(int arg1 = 1, err1 = m_mplsTesting.TestMethod(arg1))
	MSV_PROMISE_THEN_ARGS1(int arg12 = 1, err2 = m_mplsTesting.TestMethod(arg12))
	MSV_PROMISE_THEN_ARGS1(int arg13 = 1, err3 = m_mplsTesting.TestMethod(arg13))
	MSV_PROMISE_CATCH(mplsErrorcodeCheck = mplsErrorcode)

	EXPECT_EQ(err1, 0);
	EXPECT_EQ(err2, 0);
	EXPECT_EQ(mplsErrorcodeCheck, 1);
}

TEST_F(MplsTest, ItShoudntCatchErrorWithoutReason_ARGS2)
{
	EXPECT_CALL(m_mplsTesting, TestMethod(1, 2))
		.Times(3)
		.WillRepeatedly(Return(0));

	int err1 = 1;
	int err2 = 1;
	int err3 = 1;
	int mplsErrorcodeCheck = 1;

	//test
	MSV_PROMISE_ARGS2(int arg1 = 1, int arg2 = 2, err1 = m_mplsTesting.TestMethod(arg1, arg2))
	MSV_PROMISE_THEN_ARGS2(int arg12 = 1, int arg22 = 2, err2 = m_mplsTesting.TestMethod(arg12, arg22))
	MSV_PROMISE_THEN_ARGS2(int arg13 = 1, int arg23 = 2, err3 = m_mplsTesting.TestMethod(arg13, arg23))
	MSV_PROMISE_CATCH(mplsErrorcodeCheck = mplsErrorcode)

	EXPECT_EQ(err1, 0);
	EXPECT_EQ(err2, 0);
	EXPECT_EQ(mplsErrorcodeCheck, 1);
}

TEST_F(MplsTest, ItShoudntCatchErrorWithoutReason_ARGS3)
{
	EXPECT_CALL(m_mplsTesting, TestMethod(1, 2, 3))
		.Times(3)
		.WillRepeatedly(Return(0));

	int err1 = 1;
	int err2 = 1;
	int err3 = 1;
	int mplsErrorcodeCheck = 1;

	//test
	MSV_PROMISE_ARGS3(int arg1 = 1, int arg2 = 2, int arg3 = 3, err1 = m_mplsTesting.TestMethod(arg1, arg2, arg3))
	MSV_PROMISE_THEN_ARGS3(int arg12 = 1, int arg22 = 2, int arg32 = 3, err2 = m_mplsTesting.TestMethod(arg12, arg22, arg32))
	MSV_PROMISE_THEN_ARGS3(int arg13 = 1, int arg23 = 2, int arg33 = 3, err3 = m_mplsTesting.TestMethod(arg13, arg23, arg33))
	MSV_PROMISE_CATCH(mplsErrorcodeCheck = mplsErrorcode)

	EXPECT_EQ(err1, 0);
	EXPECT_EQ(err2, 0);
	EXPECT_EQ(mplsErrorcodeCheck, 1);
}

TEST_F(MplsTest, ItShoudntCatchErrorWithoutReason_ARGS4)
{
	EXPECT_CALL(m_mplsTesting, TestMethod(1, 2, 3, 4))
		.Times(3)
		.WillRepeatedly(Return(0));

	int err1 = 1;
	int err2 = 1;
	int err3 = 1;
	int mplsErrorcodeCheck = 1;

	//test
	MSV_PROMISE_ARGS4(int arg1 = 1, int arg2 = 2, int arg3 = 3, int arg4 = 4, err1 = m_mplsTesting.TestMethod(arg1, arg2, arg3, arg4))
	MSV_PROMISE_THEN_ARGS4(int arg12 = 1, int arg22 = 2, int arg32 = 3, int arg42 = 4, err2 = m_mplsTesting.TestMethod(arg12, arg22, arg32, arg42))
	MSV_PROMISE_THEN_ARGS4(int arg13 = 1, int arg23 = 2, int arg33 = 3, int arg43 = 4, err3 = m_mplsTesting.TestMethod(arg13, arg23, arg33, arg43))
	MSV_PROMISE_CATCH(mplsErrorcodeCheck = mplsErrorcode)

	EXPECT_EQ(err1, 0);
	EXPECT_EQ(err2, 0);
	EXPECT_EQ(mplsErrorcodeCheck, 1);
}

TEST_F(MplsTest, ItShoudntCatchErrorWithoutReason_ARGS5)
{
	EXPECT_CALL(m_mplsTesting, TestMethod(1, 2, 3, 4, 5))
		.Times(3)
		.WillRepeatedly(Return(0));

	int err1 = 1;
	int err2 = 1;
	int err3 = 1;
	int mplsErrorcodeCheck = 1;

	//test
	MSV_PROMISE_ARGS5(int arg1 = 1, int arg2 = 2, int arg3 = 3, int arg4 = 4, int arg5 = 5, err1 = m_mplsTesting.TestMethod(arg1, arg2, arg3, arg4, arg5))
	MSV_PROMISE_THEN_ARGS5(int arg12 = 1, int arg22 = 2, int arg32 = 3, int arg42 = 4, int arg52 = 5, err2 = m_mplsTesting.TestMethod(arg12, arg22, arg32, arg42, arg52))
	MSV_PROMISE_THEN_ARGS5(int arg13 = 1, int arg23 = 2, int arg33 = 3, int arg43 = 4, int arg53 = 5, err3 = m_mplsTesting.TestMethod(arg13, arg23, arg33, arg43, arg53))
	MSV_PROMISE_CATCH(mplsErrorcodeCheck = mplsErrorcode)

	EXPECT_EQ(err1, 0);
	EXPECT_EQ(err2, 0);
	EXPECT_EQ(mplsErrorcodeCheck, 1);
}

TEST_F(MplsTest, ItShoudntCatchErrorForVoid)
{
	EXPECT_CALL(m_mplsTesting, TestVoidMethod())
		.Times(3);

	int mplsErrorcodeCheck = 1;

	//test
	MSV_PROMISE_VOID(m_mplsTesting.TestVoidMethod())
	MSV_PROMISE_THEN_VOID(m_mplsTesting.TestVoidMethod())
	MSV_PROMISE_THEN_VOID(m_mplsTesting.TestVoidMethod())
	MSV_PROMISE_CATCH(mplsErrorcodeCheck = mplsErrorcode)

	EXPECT_EQ(mplsErrorcodeCheck, 1);
}

TEST_F(MplsTest, ItShoudContinueToNextThenIfRequestedAndShoudntCatchError)
{
	EXPECT_CALL(m_mplsTesting, TestVoidMethod()).Times(2);
	EXPECT_CALL(m_mplsTesting, TestMethod()).WillOnce(Return(2));
	EXPECT_CALL(m_mplsTesting, TestMethod(1)).WillOnce(Return(2));
	EXPECT_CALL(m_mplsTesting, TestMethod(1, 2)).WillOnce(Return(2));
	EXPECT_CALL(m_mplsTesting, TestMethod(1, 2, 3)).WillOnce(Return(2));
	EXPECT_CALL(m_mplsTesting, TestMethod(1, 2, 3, 4)).WillOnce(Return(2));
	EXPECT_CALL(m_mplsTesting, TestMethod(1, 2, 3, 4, 5)).WillOnce(Return(2));

	int err0 = 1;
	int err1 = 1;
	int err2 = 1;
	int err3 = 1;
	int err4 = 1;
	int err5 = 1;
	int mplsErrorcodeCheck = 1;

	//test
	MSV_PROMISE_VOID(m_mplsTesting.TestVoidMethod())
	MSV_PROMISE_THEN_CONTINUE(err0 = m_mplsTesting.TestMethod())
	MSV_PROMISE_THEN_CONTINUE_ARGS1(int arg11 = 1, err1 = m_mplsTesting.TestMethod(arg11))
	MSV_PROMISE_THEN_CONTINUE_ARGS2(int arg12 = 1, int arg22 = 2, err2 = m_mplsTesting.TestMethod(arg12, arg22))
	MSV_PROMISE_THEN_CONTINUE_ARGS3(int arg13 = 1, int arg23 = 2, int arg33 = 3, err3 = m_mplsTesting.TestMethod(arg13, arg23, arg33))
	MSV_PROMISE_THEN_CONTINUE_ARGS4(int arg14 = 1, int arg24 = 2, int arg34 = 3, int arg44 = 4, err4 = m_mplsTesting.TestMethod(arg14, arg24, arg34, arg44))
	MSV_PROMISE_THEN_CONTINUE_ARGS5(int arg15 = 1, int arg25 = 2, int arg35 = 3, int arg45 = 4, int arg55 = 5, err5 = m_mplsTesting.TestMethod(arg15, arg25, arg35, arg45, arg55))
	MSV_PROMISE_THEN_VOID(m_mplsTesting.TestVoidMethod())
	MSV_PROMISE_CATCH(mplsErrorcodeCheck = mplsErrorcode)

	EXPECT_EQ(err0, 2);
	EXPECT_EQ(err1, 2);
	EXPECT_EQ(err2, 2);
	EXPECT_EQ(err3, 2);
	EXPECT_EQ(err4, 2);
	EXPECT_EQ(err5, 2);
	EXPECT_EQ(mplsErrorcodeCheck, 1);
}

TEST_F(MplsTest, ItShoudDefineArgsForCalledFunctions)
{
	EXPECT_CALL(m_mplsTesting, TestVoidMethod()).Times(1);
	EXPECT_CALL(m_mplsTesting, TestMethod(1)).WillOnce(Return(0));
	EXPECT_CALL(m_mplsTesting, TestMethod(1, 2)).WillOnce(Return(0));
	EXPECT_CALL(m_mplsTesting, TestMethod(1, 2, 3)).WillOnce(Return(0));
	EXPECT_CALL(m_mplsTesting, TestMethod(1, 2, 3, 4)).WillOnce(Return(0));
	EXPECT_CALL(m_mplsTesting, TestMethod(1, 2, 3, 4, 5)).WillOnce(Return(0));

	int err1 = 1;
	int err2 = 1;
	int err3 = 1;
	int err4 = 1;
	int err5 = 1;
	int mplsErrorcodeCheck = 1;

	//test
	MSV_PROMISE_VOID(m_mplsTesting.TestVoidMethod())
	MSV_PROMISE_DEFINE_ARGS1(int arg11 = 1)
	MSV_PROMISE_THEN(err1 = m_mplsTesting.TestMethod(arg11))
	MSV_PROMISE_DEFINE_ARGS2(int arg12 = 1, int arg22 = 2)
	MSV_PROMISE_THEN(err2 = m_mplsTesting.TestMethod(arg12, arg22))
	MSV_PROMISE_DEFINE_ARGS3(int arg13 = 1, int arg23 = 2, int arg33 = 3)
	MSV_PROMISE_THEN(err3 = m_mplsTesting.TestMethod(arg13, arg23, arg33))
	MSV_PROMISE_DEFINE_ARGS4(int arg14 = 1, int arg24 = 2, int arg34 = 3, int arg44 = 4)
	MSV_PROMISE_THEN(err4 = m_mplsTesting.TestMethod(arg14, arg24, arg34, arg44))
	MSV_PROMISE_DEFINE_ARGS5(int arg15 = 1, int arg25 = 2, int arg35 = 3, int arg45 = 4, int arg55 = 5)
	MSV_PROMISE_THEN(err5 = m_mplsTesting.TestMethod(arg15, arg25, arg35, arg45, arg55))
	MSV_PROMISE_CATCH(mplsErrorcodeCheck = mplsErrorcode)

	EXPECT_EQ(err1, 0);
	EXPECT_EQ(err2, 0);
	EXPECT_EQ(err3, 0);
	EXPECT_EQ(err4, 0);
	EXPECT_EQ(err5, 0);
	EXPECT_EQ(mplsErrorcodeCheck, 1);
}

TEST_F(MplsTest, ItShoudIgnoreErrorIfRequested)
{
	EXPECT_CALL(m_mplsTesting, TestMethod(1)).WillOnce(Return(2));

	int err1 = 1;
	int mplsErrorcodeCheck = 1;

	//test
	MSV_PROMISE(err1 = m_mplsTesting.TestMethod(1))
	MSV_PROMISE_CATCH_IGNORE_ERROR

	EXPECT_EQ(err1, 2);
}

TEST_F(MplsTest, ItShoudCatchErrorIfFailed)
{
	EXPECT_CALL(m_mplsTesting, TestMethod(1)).WillOnce(Return(2));

	int err1 = 1;
	int mplsErrorcodeCheck = 1;
	int storedError = 0;

	//test
	MSV_PROMISE(err1 = m_mplsTesting.TestMethod(1))
	MSV_PROMISE_CATCH(mplsErrorcodeCheck = mplsErrorcode)

	EXPECT_EQ(err1, 2);
	EXPECT_EQ(mplsErrorcodeCheck, 2);
}

TEST_F(MplsTest, ItShoudStoreErrorIfRequested)
{
	EXPECT_CALL(m_mplsTesting, TestMethod(1)).WillOnce(Return(2));

	int err1 = 1;
	int mplsErrorcodeCheck = 1;
	int storedError = 0;

	//test
	MSV_PROMISE(err1 = m_mplsTesting.TestMethod(1))
	MSV_PROMISE_CATCH_STORE_ERROR(storedError, mplsErrorcodeCheck = mplsErrorcode)

	EXPECT_EQ(err1, 2);
	EXPECT_EQ(mplsErrorcodeCheck, 2);
}

TEST_F(MplsTest, ItShoudReturnErrorIfRequested)
{
	EXPECT_CALL(m_mplsTesting, TestMethod(1)).WillOnce(Return(2));

	//test
	EXPECT_EQ(TestCatchAndReturnFailed(), 2);
}

TEST_F(MplsTest, ItShoudntReturnErrorIfRequestedWhenNoError)
{
	EXPECT_CALL(m_mplsTesting, TestMethod(1)).WillOnce(Return(0));

	//test
	EXPECT_EQ(TestCatchAndReturnFailed(), -1);
}
