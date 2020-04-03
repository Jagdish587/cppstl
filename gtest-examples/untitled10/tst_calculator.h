#ifndef TST_CALCULATOR_H
#define TST_CALCULATOR_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <gmock/gmock.h>
#include <string>

using namespace testing;
using namespace std;
using ::testing::AtLeast;
using ::testing::_;
using ::testing::Invoke;
using ::testing::InvokeWithoutArgs;
using ::testing::Return;

// Assume This is Interface Class
class DatabaseConnect {
 public:

  virtual bool logging (string username, string password) {
    cout<<"Jagdish *************************** entered logging \n";
    return true;
  }
  virtual bool logout (string username, string password) {
    return false;
  }
  virtual int fetchrecord() {
    return -1;
  }

  virtual ~DatabaseConnect() {

  }

};

class MockDatabaseConnect : public DatabaseConnect {
 public:

  MOCK_METHOD2(logging, bool(string username, string password));
  MOCK_METHOD2(logout, bool(string username, string password));
  MOCK_METHOD0(fetchrecord, int());

};

class MyDatabase {

  DatabaseConnect &dbs;
  string musername;
  string mpassword;

 public:

  MyDatabase(DatabaseConnect &rdbs) : dbs(rdbs) {

  }

  int init(string username, string password) {
    cout<<"entered init here \n";
    int val = dbs.logging(username, password);
    cout<<"logging val = "<<val<<endl;
    return val;
  }
};



class Myclass {
 public:
  int vala;
  int valb;

  Myclass(int a, int b) {
    vala =  a;
    valb = b;
  }

  void setdata(int a, int b) {
    vala = a;
    valb = b;
  }

  void display() {
    cout<<"vala = "<<vala<<" valb = "<<valb<<endl;
  }
};

class MyclassTest : public testing::Test {
 public:
  Myclass *mcobj ;

  void SetUp() {
    cout<<"entered setup \n";
    mcobj = new Myclass(24,68);
  }

  void TearDOwn() {
    cout<<"entered teardown \n";
    delete mcobj;
  }

};

TEST(Calculator, CalculatorsSet)
{
  EXPECT_EQ(1, 1);
  ASSERT_THAT(0, Eq(0));
}

void somefunc()
{
  std::cout<<"i am inside somefunc \n";
}

TEST(Calculator, CalculatorsSet1)
{
   std::cout<<"Jagdish i am inside test case \n";
   somefunc();
   EXPECT_EQ(2, 2);
}

TEST_F(MyclassTest , testdata1) {

  cout<<"Entered Test Fixture ";
  mcobj->display();

  cout<<"setting data \n ";
  mcobj->setdata(24,36);

  mcobj->display();
}

TEST(MYDBTEST, LoginTest)
{
  // Step1: Arrange the test case
  // Step2: Act on test case
  // Step3: Aseert on test case

  MockDatabaseConnect mockobj;
  MyDatabase mydb(mockobj);

  EXPECT_CALL(mockobj, logging(_, _)).Times(1).WillRepeatedly(Return(true));

  int ret = mydb.init("Jagdish","Howryou");
  EXPECT_EQ(ret, 1);

}


TEST(MYDBTEST, LoginTest2)
{
  // Step1: Arrange the test case
  // Step2: Act on test case
  // Step3: Aseert on test case

  // what if you want to invoke original func along wigth mock func

  MockDatabaseConnect mockobj;
  MyDatabase mydb(mockobj);
  DatabaseConnect dbtest;

  EXPECT_CALL(mockobj, logging(_, _)).Times(1).WillOnce(Invoke(&dbtest,&DatabaseConnect::logging));

  int ret = mydb.init("Jagdish","Howryou");
  EXPECT_EQ(ret, 1);

}


struct testABC {

  bool dummylogging(string aa, string bb) {
    cout<<"entered inside struct dummylogging \n";
    return true;
  }

};

TEST(MYDBTEST, LoginTest3)
{
  // Step1: Arrange the test case
  // Step2: Act on test case
  // Step3: Aseert on test case

  // what if you want to invoke some custom function

  MockDatabaseConnect mockobj;
  MyDatabase mydb(mockobj);
  testABC structdbtest;

  EXPECT_CALL(mockobj, logging(_, _)).Times(1).WillOnce(Invoke(&structdbtest,&testABC::dummylogging));

  int ret = mydb.init("Jagdish","Howryou");
  EXPECT_EQ(ret, 1);

}



bool globaldummyfunc()
{
  cout<<"insiode globaldummyfunc \n";
  return true;
}

TEST(MYDBTEST, LoginTest4)
{
  // Step1: Arrange the test case
  // Step2: Act on test case
  // Step3: Aseert on test case

  // what if you want to invoke some global function
  // the function should be without arguments

  MockDatabaseConnect mockobj;
  MyDatabase mydb(mockobj);

  EXPECT_CALL(mockobj, logging(_, _)).Times(1).WillOnce(InvokeWithoutArgs(globaldummyfunc));

  int ret = mydb.init("Jagdish","Howryou");
  EXPECT_EQ(ret, 1);

}

struct testXYZ {

  bool dummylogging(string aa, string bb) {
    cout<<"entered inside struct dummylogging xyz \n";
   // return true;

  }
};

#if 0
TEST(MYDBTEST, LoginTest5)
{
  // Step1: Arrange the test case
  // Step2: Act on test case
  // Step3: Aseert on test case

  // what if you want to invoke some global function
  // the function should be without arguments

  MockDatabaseConnect mockobj;
  MyDatabase mydb(mockobj);
  testXYZ objxyz;

   // EXPECT_CALL(mockobj, logging(_, _)).Times(1).WillOnce(Invoke(&objxyz,&testXYZ::dummylogging));

  EXPECT_CALL(mockobj, logging(_, _)).Times(1).WillOnce(DoAll(Invoke(&objxyz,&testXYZ::dummylogging),
                                                              InvokeWithoutArgs(globaldummyfunc).Return(true)));

  int ret = mydb.init("Jagdish","Howryou");
  EXPECT_EQ(ret, 1);

}
#endif


#endif // TST_CALCULATOR_H



