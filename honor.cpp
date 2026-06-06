#include "honor.h"
#include "types.h"
#include <cstdlib>
#include <algorithm>

using namespace std;

int coldStartScore() {
    return 60 + rand() % 11; // 60..70
}

void adjustHonorScore(const string& userId, int delta, const string&) {
    if (!users.count(userId)) return;
    users[userId].honorScore = max(0, min(100, users[userId].honorScore + delta));
}

bool shouldWarnUser(const string& userId) {
    if (!users.count(userId)) return false;
    return users[userId].honorScore < 40;
}
