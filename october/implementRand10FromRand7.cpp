// Given the API rand7() that generates a uniform random integer in the range [1, 7], write a function rand10() that generates a uniform random integer in the range [1, 10]. You can only call the API rand7(), and you shouldn't call any other API. Please do not use a language's built-in random API.
// Each test case will have one internal argument n, the number of times that your implemented function rand10() will be called while testing. Note that this is not an argument passed to rand10().


/*
    we will be making sure tha every number is equally probable
    for that I have mapped 1-3 numbers to 1-5
    and 4-6 numbers to 6-10
    if we ever gets 7 we will re-roll the dice in this case rand7()
    And similarly I have taken a variable which gets a value from 1-5
    which we will be manipulating

*/



// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7



class Solution {
public:
    int rand10() {
        int r1 = rand7();
        while (r1 > 5) {
            r1 = rand7();
        }

        //r1 is from 1 to 5

        int r2 = rand7();
        while (r2 > 6) {
            r2 = rand7();
        }

        //mapped r2 as descrepted above.

        return r2 < 4 ? r1 : r1 + 5;
    }
};
