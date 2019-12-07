#define countof(a) (sizeof(a)/sizeof((a)[0]))

void emptyArrayTest(Test *tc)
{
    const int result = contains(NULL, 0, 1);
    AssertFalse(tc, result);
}

void oneItemArrayNumberPresentTest(Test *tc)
{
    const int a[] = {1};
    const int result = contains(a, countof(a), 1);
    AssertTrue(tc, result);
}

void oneItemArrayNumberAbsentTest(Test *tc)
{
    const int a[] = {1};
    const int result = contains(a, countof(a), 2);
    AssertFalse(tc, result);
}

void smallArrayNumberPresentTest(Test *tc)
{
    const int a[] = {2, 4, 6};
    const int result = contains(a, countof(a), 4);
    AssertTrue(tc, result);
}

void smallArrayNumberAbsentTest(Test *tc)
{
    const int a[] = {2, 4, 6};
    const int result = contains(a, countof(a), 5);
    AssertFalse(tc, result);
}

void largeArrayNumberPresentTest(Test *tc)
{
    const int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int result = contains(a, countof(a), 8);
    AssertTrue(tc, result);
}

void largeArrayNumberAbsentTest(Test *tc)
{
    const int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int result = contains(a, countof(a), 0);
    AssertFalse(tc, result);
}

void largeArrayNumberFirstTest(Test *tc)
{
    const int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int result = contains(a, countof(a), 1);
    AssertTrue(tc, result);
}

void largeArrayNumberLastTest(Test *tc)
{
    const int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int result = contains(a, countof(a), 10);
    AssertTrue(tc, result);
}

int main()
{
    TestSuite *tests = TestSuiteNew();

    SUITE_ADD_TEST(tests, emptyArrayTest);
    SUITE_ADD_TEST(tests, oneItemArrayNumberPresentTest);
    SUITE_ADD_TEST(tests, oneItemArrayNumberAbsentTest);
    SUITE_ADD_TEST(tests, smallArrayNumberPresentTest);
    SUITE_ADD_TEST(tests, smallArrayNumberAbsentTest);
    SUITE_ADD_TEST(tests, largeArrayNumberPresentTest);
    SUITE_ADD_TEST(tests, largeArrayNumberAbsentTest);
    SUITE_ADD_TEST(tests, largeArrayNumberFirstTest);
    SUITE_ADD_TEST(tests, largeArrayNumberLastTest);

    TestSuiteRun(tests);
    TestSuiteDelete(tests);

    return 0;
}
