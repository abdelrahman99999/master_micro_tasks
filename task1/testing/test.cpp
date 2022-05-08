#include <gtest/gtest.h>
#include<gmock/gmock.h>
#include "../Application/Function_Plotter/math_operation.h"

class vaildate_input_get_result_TEST: public testing::Test{
public:
    double x;
    std::string expression;
    int err;
    void SetUp() override{

    }
    //tears down the test fixture
    void TearDown() override{

    }

};

TEST_F(vaildate_input_get_result_TEST,test_1){
    x=-0.4;
    expression="5*x^3 + 2*x";
    double result = math_operation::vaildate_input_get_result(expression,x);
    double expected=-1.12;

    EXPECT_DOUBLE_EQ(expected,result);
}


TEST_F(vaildate_input_get_result_TEST,test_2){
    x=3;
    expression="x^2+1";
    double result = math_operation::vaildate_input_get_result(expression,x);
    double expected=10;

    EXPECT_DOUBLE_EQ(expected,result);
}

TEST_F(vaildate_input_get_result_TEST,test_3){
    x=5;
    expression="x/2 + 10*10";
    double result = math_operation::vaildate_input_get_result(expression,x);
    double expected=102.5;

    EXPECT_DOUBLE_EQ(expected,result);
}

TEST_F(vaildate_input_get_result_TEST,test_4){
    x=-3;
    expression="x-x-x";
    double result = math_operation::vaildate_input_get_result(expression,x);
    double expected=3;

    EXPECT_DOUBLE_EQ(expected,result);
}

TEST_F(vaildate_input_get_result_TEST,test_5){
    x=1;
    expression="x+y";
    EXPECT_THROW(math_operation::vaildate_input_get_result(expression,x), Invaild_Expression);
}

TEST_F(vaildate_input_get_result_TEST,test_6){
    x=1;
    expression="12@x+5";
    EXPECT_THROW(math_operation::vaildate_input_get_result(expression,x), Invaild_Expression);
}

TEST_F(vaildate_input_get_result_TEST,test_7){
    x=8;
    expression="x^4 + x*x - 3*x";
    EXPECT_NO_THROW(math_operation::vaildate_input_get_result(expression,x));
}

TEST_F(vaildate_input_get_result_TEST,test_8){
    x=30;
    expression="sin(x*pi/180)/0.5";
    double result = math_operation::vaildate_input_get_result(expression,x);
    double expected=1;
    EXPECT_DOUBLE_EQ(expected,result);
}

TEST_F(vaildate_input_get_result_TEST,test_9){
    x=5;
    expression="(x+5";
    EXPECT_THROW(math_operation::vaildate_input_get_result(expression,x),Invaild_Expression);
}
TEST_F(vaildate_input_get_result_TEST,test_10){
    x=10;
    expression="x+e";
    double result = math_operation::vaildate_input_get_result(expression,x);
    double expected=12.718;
    EXPECT_NEAR(expected,result,0.1);
}

int main()
{
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
