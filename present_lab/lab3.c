# include <stdio.h>
# include <math.h>

// ส่วยเบี่ยนเบนมาตรฐาน, ความแปรปรวน, ส่วนเบี่ยงเบนเฉลี่ย, สัมประสิทธิพิสัย, 
// มัธยฐาน, ฐานนนิยม, ค่าเฉลี่ย, น้อยสุด-มากสุด, range, ส่วนเบี่ยงเบนควอร์ไทล์
int main(void) {
    int count = 0;
    float a[100000];
    printf("Enter number : ");
    do {
        scanf("%f", &a[count]);
        count++;
    } while (getchar() != '\n');
    a[count];
//-----------------------------------------------------------------------
//  1. Mean
    float totalavg = 0;
    for (int i = 0; i < count; i++){
        totalavg += a[i];
    }
    float avg = totalavg / count;
    printf("Average: %.2f\n", avg);
//-----------------------------------------------------------------------
//  1.1) lower to higher
    float b;
    for (int i = 0; i < count; i++){
        for (int j = i + 1; j < count; j++){
            if (a[i] > a[j]){
                b = a[i];
                a[i] = a[j];
                a[j] = b;
            }
        }
    }

//-----------------------------------------------------------------------
//  1.2) Max-Min
    float min = a[0], max = a[count];
    for (int i = 0; i < count; i++) {
        if (a[i] < min) {
            min = a[i];
        }
        else if (a[i] > max){
            max = a[i];
        }
    }
    printf("Max: %.2f, Min: %.2f\n", max, min);
//-----------------------------------------------------------------------
//  range
    float range = max - min;
    printf("Range: ");
    if (range == 0){
        printf("All number are same\n");
    }
    else{
        printf("%.2f\n", range);
    }
//-----------------------------------------------------------------------
//  2. median
    for (int i = 0; i < 1; i++){
        float median;
        if (count % 2 == 0){
            median = (a[count / 2] + a[(count / 2) - 1]) / 2;
        }
        else {
            median = a[count / 2];
        }
        printf("Median: %.2f\n", median);
    }
//-----------------------------------------------------------------------
//  3. Mode
//  3.1) remove duplicate
    int z = 0, d[count];
    for (int i = 1; i < count; i++){
        d[0] = a[0];
        if (a[i-1] != a[i]){
            z++;
            d[z] = a[i];
        }
    }
//-----------------------------------------------------------------------
//  3.2) count number of each number
    int total = 0, time[z];
    for(int i = 0; i < z + 1; i++){
        for (int j = 0; j < count; j++){
            if (d[i] == a[j]){
                total++;
            }
        }
    time[i] = total;
    total = 0;
    // printf("%d\n", time[i]);
    }
//-----------------------------------------------------------------------
//  3.3) Print Mode
    int maxtime = time[0], tmode = 0;
    for (int i = 0; i < z; i++){
        if (time[i] < time[i + 1]){
            maxtime = time[i + 1];
        }
    }
    // printf("%d\n", maxtime);
    float mode[z]; int mt = 0;
    for (int i = 0; i < z + 1; i++){
        if (time[i] == maxtime){
            mode[mt] = d[i];
            tmode++;
            mt++;
        }
    }
    // printf("%d %d %d\n", mode[0], d[0] , tmode);
    mode[tmode];
    // printf("%d %d\n", tmode, z / 2 + 1);
    printf("Mode: ");
    int colon = tmode;
    if (tmode <= z / 2 + 1) {
        for (int j = 0; j < tmode; j++){
            printf("%.2f ", mode[j]);
            if (colon > 1){
                printf(",");
                colon--;
            }
        }
    }
    else {
        printf("-\n");
    }
//-----------------------------------------------------------------------
//  4.Q.D. (q3-q1)/2
    float q1, q3, QD;
    if (count % 2 == 0){
        q1 = (a[count / 4] + a[(count / 4) - 1]) / 2;
        q3 = (a[(count / 4) * 3] + a[((count / 4) * 3) - 1]) / 2;
    }
    else {
        q1 = a[count / 4];
        q3 = a[(count / 4) * 3];
    }
    QD = (q3 - q1) / 2;
    printf("\nQ.D.: %.2f\n", QD);
}