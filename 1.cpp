#include <cstdio>
#include <cmath>
#include <vector>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        std::vector<int> start_time(1001, -1);
        int total_duration = 0;
        int count = 0;
        int book_id, hh, mm;
        char action;
        while (scanf("%d", &book_id) == 1 && book_id != 0) {
            scanf(" %c %d:%d", &action, &hh, &mm);
            int current_time = hh * 60 + mm;
            if (action == 'S') {
                if (book_id > 0 && book_id < 1001) {
                    start_time[book_id] = current_time;
                }
            } else if (action == 'E') {
                if (book_id > 0 && book_id < 1001 && start_time[book_id] != -1) {
                    total_duration += current_time - start_time[book_id];
                    count++;
                    start_time[book_id] = -1;
                }
            }
        }
        if (count == 0) {
            printf("0 0\n");
        } else {
            int avg_time = round((double)total_duration / count);
            printf("%d %d\n", count, avg_time);
        }
    }
    return 0;
}
