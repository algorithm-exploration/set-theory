const lest::test tests[] = {
    CASE("empty vector") {
        const vector<int> v;
        EXPECT(contains(v, 1) == false);
    },
    CASE("one item vector number present") {
        const vector<int> v {1};
        EXPECT(contains(v, 1) == true);
    },
    CASE("one item vector number absent") {
        const vector<int> v {1};
        EXPECT(contains(v, 2) == false);
    },
    CASE("small vector number present") {
        const vector<int> v {2, 4, 6};
        EXPECT(contains(v, 4) == true);
    },
    CASE("small vector number absent") {
        const vector<int> v {2, 4, 6};
        EXPECT(contains(v, 5) == false);
    },
    CASE("large vector number present") {
        const vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        EXPECT(contains(v, 8) == true);
    },
    CASE("large vector number absent") {
        const vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        EXPECT(contains(v, 0) == false);
    },
    CASE("large vector number first") {
        const vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        EXPECT(contains(v, 1) == true);
    },
    CASE("large vector number last") {
        const vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        EXPECT(contains(v, 10) == true);
    }
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}
