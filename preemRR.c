#include <stdio.h>
struct Process {
int id, at, bt, rt, ft, wt, tat;
};
int main() {
int n, tq, time = 0, done = 0;
printf("Enter number of processes: ");
scanf("%d", &n);
struct Process p[n];
int visited[n], q[100], front = 0, rear = 0;
for (int i = 0; i < n; i++) {
printf("P%d AT & BT: ", i+1);
scanf("%d%d", &p[i].at, &p[i].bt);
p[i].id = i+1;
p[i].rt = p[i].bt;
visited[i] = 0;
}
printf("Enter Time Quantum: ");
scanf("%d", &tq);
for (int i = 0; i < n; i++)
if (p[i].at == 0) { q[rear++] = i; visited[i] = 1; }
while (done < n) {
if (front == rear) {
time++;
for (int i = 0; i < n; i++)
if (!visited[i] && p[i].at <= time) { q[rear++] = i; visited[i] = 1; }
continue;
}
int i = q[front++], slice = (p[i].rt > tq) ? tq : p[i].rt;
p[i].rt -= slice;
time += slice;
for (int j = 0; j < n; j++)
if (!visited[j] && p[j].at <= time) {
q[rear++] = j; visited[j] = 1; }
if (p[i].rt > 0)
q[rear++] = i;
else {
p[i].ft = time;
p[i].tat = p[i].ft - p[i].at;
p[i].wt = p[i].tat - p[i].bt;
done++;
}
}
printf("\nP#\tAT\tBT\tFT\tWT\tTAT\n");
for (int i = 0; i < n; i++)
printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at , p[i].bt, p[i].ft, p[i].wt, p[i].tat);
return 0;
}