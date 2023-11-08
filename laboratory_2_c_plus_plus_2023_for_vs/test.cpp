#include <iostream>
#include <string>
#include "work_with_strings.h"

using namespace std;


bool test_1() {
  string text = "hehehello testtesssss";
  string correct_text = "'#)!-%+";
  string received_text = work_for_test(text);

  if (received_text == correct_text) {
    return true;
  } else {
    cout << "Test 1 failed!" << endl;
    cout << "Correct encrypted text: " << correct_text << endl;
    cout << "Received text: " << received_text << endl;
    return false;
  }
}

bool test_2() {
  string text = "///something    ffff";
  string correct_text = "!-'+#%)";
  string received_text = work_for_test(text);

  if (received_text == correct_text) {
    return true;
  } else {
    cout << "Test 2 failed!" << endl;
    cout << "Correct encrypted text: " << correct_text << endl;
    cout << "Received text: " << received_text << endl;
    return false;
  }
}

bool test_3() {
  string text = "ffffffffffxxxxxxxxxwwwwhell";
  string correct_text = "\"\"\"$**(& ";
  string received_text = work_for_test(text);

  if (received_text == correct_text) {
    return true;
  } else {
    cout << "Test 3 failed!" << endl;
    cout << "Correct encrypted text: " << correct_text << endl;
    cout << "Received text: " << received_text << endl;
    return false;
  }
}

bool test_4() {
  string text = "heyhey";
  string correct_text = "  ";
  string received_text = work_for_test(text);

  if (received_text == correct_text) {
    return true;
  } else {
    cout << "Test 4 failed!" << endl;
    cout << "Correct encrypted text: " << correct_text << endl;
    cout << "Received text: " << received_text << endl;
    return false;
  }
}

bool test_5() {
  string text = "great job job job";
  string correct_text = "'#)!%+";
  string received_text = work_for_test(text);

  if (received_text == correct_text) {
    return true;
  } else {
    cout << "Test 5 failed!" << endl;
    cout << "Correct encrypted text: " << correct_text << endl;
    cout << "Received text: " << received_text << endl;
    return false;
  }
}

void checking_tests() {
  int test_counter{};
  const int ALL_TESTS_PASSED{ 5 };

  if (test_1()) {
    test_counter++;
  }
  if (test_2()) {
    test_counter++;
  }
  if (test_3()) {
    test_counter++;
  }
  if (test_4()) {
    test_counter++;
  }
  if (test_5()) {
    test_counter++;
  }
  if (test_counter == ALL_TESTS_PASSED) {
    cout << "All tests passed successfully!" << endl;
  }
}