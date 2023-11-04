//
// Created by 22755 on 2023/1/29.
//
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <cura.h>
#include "stdbool.h"
#include "math.h"

#define WIDTH 6
#define HEIGHT 6

//升序数组
int search(const int *nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (nums[middle] < target) {
            left = middle + 1;
        } else if (nums[middle] > target) {
            right = middle - 1;
        } else {
            return middle;
        }
    }
    return -1;
}

//搜索插入位置
int searchInsert(const int *nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    int ans = numsSize;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (target <= nums[middle]) {
            ans = middle;
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
    return ans;
}

//双指针计算
int *twoSum(int *numbers, int numbersSize, int target, int *returnSize) {
    int i = 0, j = numbersSize - 1;
    int *ret = malloc(sizeof(int) * 2);
    while (i <= j) {
        if (numbers[i] + numbers[j] == target) {
            ret[0] = i + 1;
            ret[1] = j + 1;
            *returnSize = 2;
            return ret;
        } else if (numbers[i] + numbers[j] < target) {
            ++i;
        } else {
            --j;
        }
    }
    *returnSize = 0;
    free(ret);
    return NULL;
}

int lengthOfLongestSubstring(char *s) {
    int length = 0, maxlength = 0;
    int start = 0, index[128] = {0};
    for (int j = 0; j < strlen(s); j++) {
        if (index[s[j]] > start) {
            length = j - start;
            start = index[s[j]];
            if (length > maxlength) {
                maxlength = length;
            }
        }
        index[s[j]] = j + 1;
    }
    length = strlen(s);
    if (length - start > maxlength) {
        return length - start;
    } else {
        return maxlength;
    }
}

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size) {
    double index[nums1Size + nums2Size];
    double num;
    double Result;
    for (int i = 0; i < nums1Size + nums2Size; i++) {
        if (i < nums1Size) {
            index[i] = nums1[i];
        } else {
            index[i] = nums2[i - nums1Size];
        }
    }
    for (int j = 1; j < nums1Size + nums2Size; j++) {
        if (index[j - 1] > index[j]) {
            num = index[j - 1];
            index[j - 1] = index[j];
            index[j] = num;
            j = j - 2;
            if (j <= 0) {
                j = 0;
            }
        }
    }
    if ((nums1Size + nums2Size) % 2 == 0) {
        Result = (index[((nums1Size + nums2Size) / 2) - 1] + index[((nums1Size + nums2Size) / 2)]) / 2.0f;
    } else {
        Result = (index[((nums1Size + nums2Size) / 2)]) / 1.0f;
    }
    return Result;
}

int *sortedSquares(int *nums, int numsSize, int *returnSize) {
    int *index = malloc(sizeof(int) * numsSize);
    int num;
    for (int i = 0; i < numsSize; i++) {
        index[i] = nums[i] * nums[i];
    }
    for (int j = 1; j < numsSize; j++) {
        if (index[j - 1] > index[j]) {
            num = index[j - 1];
            index[j - 1] = index[j];
            index[j] = num;
            j = j - 2;
            if (j <= 0) {
                j = 0;
            }
        }
    }
    *returnSize = numsSize;
    return index;
}

void rotate(int *nums, int numsSize, int k) {
    int index[numsSize];
    for (int i = 0; i < numsSize; ++i) {
        index[(i + k) % numsSize] = nums[i];
    }
    for (int i = 0; i < numsSize; ++i) {
        nums[i] = index[i];
    }
}

void moveZeroes(int *nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            for (int j = i; j < numsSize; j++) {
                if (nums[j] != 0) {
                    nums[i] = nums[j];
                    nums[j] = 0;
                    break;
                }
            }
        }
    }
}

char *longestPalindrome(char *s) {
    int left = 0, right = 0;
    int i, j, k, max = 0, m = 0;
    static char index[2000];
    memset(index, 0, sizeof(index));
    for (i = 0; i < strlen(s); i++) {
        for (j = i; j < strlen(s); j++) {
            for (k = 0; k <= (j - i) / 2; k++) {
                if (s[i + k] != s[j - k]) {
                    break;
                }
            }
            if (k > (j - i) / 2 && j - i + 1 > max) {
                max = j - i + 1;
                left = i;
                right = j;
            }
        }
    }
    for (i = left; i <= right; i++) {
        index[m] = s[i];
        m++;
        if (m == right - left + 1) {
            return index;
        }
    }
//    while (left <= right) {
//        if (s[left] != s[right]) {
//            right--;
//        } else {
//            memset(index, 0, sizeof(index));
//            if (left == strlen(s) - 1) {
//                index[0] = s[0];
//                return index;
//            }
//            for (int i = left; i < right + 1; i++) {
//                index[j] = s[i];
//                j++;
//                if (j == (right - left + 1)) {
//                    return index;
//                }
//            }
//        }
//        if ((right - left) == 0) {
//            left++;
//            right = (int) strlen(s) - 1;
//        }
//    }
//    return s;
}
//最长回文子串

void reverseString(char *s, int sSize) {
    char temp;
    for (int i = 0; i < sSize / 2; i++) {
        temp = s[i];
        s[i] = s[sSize - 1 - i];
        s[sSize - 1 - i] = temp;
    }
}

char *reverseWords(char *s) {
    int left = 0, right = 0;
    char temp;
    for (left = 0; left < strlen(s); left++) {
        for (right = left; right < strlen(s); right++) {
            if (s[right] == ' ') {
                break;
            }
        }
        for (int i = left, j = right - 1; i < j; ++i, --j) {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
        left = right;
    }
    return s;
}

struct ListNode *middleNode(struct ListNode *head) {
    //快慢指针
    struct ListNode *slow = head, *fast = head;
    while (slow != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
        }
    }
    return slow;
    //单指针解法
//    struct ListNode *pre = head;
//    int i = 0, j = 0;
//    while (pre != NULL) {
//        pre = pre->next;
//        i++;
//    }
//    pre = head;
//    while (j < i / 2) {
//        pre = pre->next;
//        j++;
//    }
//    return pre;
}

struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    struct ListNode *space = malloc(sizeof(struct ListNode));
    space->val = 0;
    space->next = head;
    int length = 0, j;
    while (head != NULL) {
        head = head->next;
        length++;
    }
    struct ListNode *p = space;
    for (j = 1; j < length - n + 1; ++j) {
        p = p->next;
    }
    p->next = p->next->next;//p的下一个节点是我们要删除的节点，只需要将p的下一个节点指向p的下下个节点即可
    if (p == NULL) {
        return head->next;
    }
    struct ListNode *ans = space->next;
    free(space);
    return ans;
}

int countAsterisks(char *s) {
    int count = 0, left = 0, right = 0;
    while (left + right < 2 * strlen(s)) {
        for (right = left; right < strlen(s); right++) {
            if (s[right] == '|' && s[left] == '|' && right != left) {
                break;
            } else if (s[left] != '|') {
                if (s[left] == '*') {
                    count++;
                }
                left++;
                right = left - 1;
            }
        }
        for (left = right + 1; left < strlen(s); left++) {
            if (s[left] == '*') {
                count++;
            } else if (s[left] == '|') {
                right = left + 1;
                break;
            }
        }
    }
    return count;
}

int reverse(int x) {
    int rev = 0;
    while (x != 0) {
        if (rev > INT_MAX / 10 || rev < INT_MIN / 10)
            return 0;
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    return rev;
}

bool checkInclusion(char *s1, char *s2) {
    int j = 0;
    for (int i = 0; i < strlen(s2); i++) {

    }

}


const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, 1, -1, 0};

int floodFill(int imageSize, int sr, int sc, int color) {
    int x = 0, y = 0, new_x = 0, new_y = 0, currcolor = 0;
//    int n = imageSize, m = imageColSize[0];
//    *returnColumnSizes = malloc(sizeof(int) * imageSize);
//    *returnSize = n;
//    for (int i = 0; i < n; i++) {
//        (*returnColumnSizes)[i] = m;
//    }
    int image[3][3] = {
            1, 1, 1,
            1, 1, 0,
            1, 0, 1
    };
    currcolor = image[sr][sc];
    if (currcolor == color) {
        return 0;
    }
    int que[imageSize][2];
    int l = 0, r = 0;
    que[r][0] = sr;
    que[r++][1] = sc;
    image[sr][sc] = color;
    while (l < r) {
        x = que[l][0], y = que[l++][1];
        for (int j = 0; j < 4; j++) {
            new_x = x + dx[j], new_y = y + dy[j];
            if (new_x >= 0 && new_x < 9 && new_y >= 0 && new_y < 9 && image[new_x][new_y] == currcolor) {
                que[r][0] = new_x;
                que[r++][1] = new_y;
                image[new_x][new_y] = color;
            }
        }
    }
    return 0;
}


unsigned char input[WIDTH][HEIGHT];  // 存储原始图像的数组
unsigned char output[WIDTH][HEIGHT]; // 存储处理后的图像的数组

void binarize() {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (input[i][j] > THRESHOLD) {
                output[i][j] = 255;
            } else {
                output[i][j] = 0;
            }
        }
    }
}

void findLine() {
    int i, j;
    int left, right;
    int mid = HEIGHT / 2;
    for (i = 0; i < WIDTH; i++) {
        left = -1;
        right = -1;
        for (j = mid; j < HEIGHT; j++) {
            if (output[i][j] == 0) {
                if (left == -1) {
                    left = j;
                } else {
                    right = j;
                    break;
                }
            }
        }
        if (left != -1 && right != -1) {
            output[i][mid] = 0;
            output[i][(left + right) / 2] = 127;
        }
    }
}

int process() {
    // 读取原始图像
    FILE *fp = fopen("E:\\Code\\input.raw", "rb");
    fread(input, sizeof(unsigned char), WIDTH * HEIGHT, fp);
    fclose(fp);

    // 二值化处理
    binarize();

    // 八邻域寻线
    findLine();

    // 保存处理后的图像
    fp = fopen("E:\\Code\\output.bmp", "wb");
    fwrite(output, sizeof(unsigned char), WIDTH * HEIGHT, fp);
    fclose(fp);

    return 0;
}


// 定义队列结构体
typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *data;
    int front;
    int rear;
} Queue;

//// 定义队列相关操作函数
void initQueue(Queue *q) {
    q->data = (Point *) malloc(WIDTH * HEIGHT * sizeof(Point));
    q->front = 0;
    q->rear = 0;
}

void enqueue(Queue *q, int x, int y) {
    q->data[q->rear].x = x;
    q->data[q->rear].y = y;
    q->rear++;
}

Point dequeue(Queue *q) {
    Point p = q->data[q->front];
    q->front++;
    return p;
}

int isQueueEmpty(Queue *q) {
    return q->front == q->rear;
}

// 广度优先搜索函数
void bfs(int image[][WIDTH], int width, int height, int x, int y, int boundary[][WIDTH]) {
    Queue q;
    initQueue(&q);
    enqueue(&q, x, y);
    boundary[y][x] = 1;
    int lastx = 0, lasty = 0;
    while (!isQueueEmpty(&q)) {
        Point p = dequeue(&q);
        int x = p.x;
        int y = p.y;
        int dx[] = {1, 1, 0, -1, -1, -1};
        int dy[] = {0, -1, -1, -1, 0, 1};
        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < width && ny >= 0 && ny < height && image[ny][nx] == 0 && image[lasty][lastx] == 255 &&
                boundary[ny][nx] == 0) {
                enqueue(&q, nx, ny);
                boundary[ny][nx] = 1;
            }
            lastx = nx;
            lasty = ny;
        }
    }
}


int point[WIDTH * HEIGHT][2] = {0};
int front = 0;
int rear = 0;

void enq(int x, int y) {
    point[rear][0] = x;
    point[rear][1] = y;
    rear++;
}

// 广度优先搜索函数
void bfs_s(int image[][WIDTH], int width, int height, int x, int y, int boundary[][WIDTH]) {
    memset(point, 0, sizeof(point));
    front = 0;
    rear = 0;
    enq(x, y);
    boundary[y][x] = 1;
    int lastx = 0, lasty = 0;
    while (front != rear) {
        int x1 = point[front][0];
        int y1 = point[front][1];
        front++;
        int dx[] = {0, -1, 0, 0, 1, 1, 0, 0};
        int dy[] = {1, 0, -1, -1, 0, 0, -1, -1};
        for (int i = 0; i < 8; i++) {
            int nx = x1 + dx[i];
            int ny = y1 + dy[i];
            if (nx >= 0 && nx < width && ny >= 0 && ny < height && image[ny][nx] == 255 && image[lasty][lastx] == 0 &&
                boundary[ny][nx] == 0) {
                enq(nx, ny);
                boundary[ny][nx] = 1;
            }
            lastx = nx;
            lasty = ny;
        }
    }
}

int compar(const void *a, const void *b) { return *(int *) a - *(int *) b; }

bool containsDuplicate(int *nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compar);
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return true;
        }
    }
    return false;
}

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int min(int a, int b) {
    if (a < b) return a;
    else return b;
}

void Sauvola(unsigned char **GrayImage, unsigned char **Pixle, int Hight, int Weight, float k, int P_W_H) {

    int whalf = P_W_H >> 1;//图像中心到两边的范围
    unsigned char rowsum_image[Hight][Weight];
    unsigned char rowsum_sqimage[Hight][Weight];
    unsigned char integral_image[Hight][Weight];
    unsigned char integral_sqimage[Hight][Weight];
    for (int j = 0; j < Hight; j++) {
        rowsum_image[j][0] = GrayImage[j][0];//记录下第零列的灰度值
    }
    for (int i = 1; i < Hight; i++) {
        for (int j = 0; j < Weight; j++) {
            //计算图像范围内任意宽度窗口(邻域)的灰度值之和
            rowsum_image[i][j] = rowsum_image[i - 1][j] + GrayImage[i][j];
            //计算图像范围内任意宽度窗口(邻域)的灰度值平方之和
            rowsum_sqimage[i][j] = rowsum_sqimage[i - 1][j] + GrayImage[i][j] * GrayImage[i][j];
        }
    }

    for (int i = 0; i < Weight; i++) {
        integral_image[0][i] = rowsum_image[0][i];
        integral_sqimage[0][i] = rowsum_sqimage[0][i];
    }
    for (int i = 0; i < Hight; i++) {
        for (int j = 1; j < Weight; j++) {
            //计算图像范围内任意宽度窗口(邻域)的灰度值的积分
            integral_image[i][j - 1] = integral_image[i][j - 1] + rowsum_image[i][j];
            //计算图像范围内任意宽度窗口(邻域)的灰度值平方的积分
            integral_sqimage[i][j - 1] = integral_sqimage[i][j - 1] + rowsum_sqimage[i][j];
        }
    }

    int xmin, ymin, xmax, ymax;
    double mean, std, threshold;
    double diagsum, idiagsum, diff, sqdiagsum, sqidiagsum, sqdiff, area;

    for (int i = 0; i < Hight; i++) {
        for (int j = 0; j < Weight; j++) {
            xmin = max(0, j - whalf);
            ymin = max(0, i - whalf);
            xmax = min(Weight - 1, j + whalf);
            ymax = min(Hight - 1, i + whalf);
            area = (xmax - xmin + 1) * (ymax - ymin + 1);
            if (area <= 0) continue;
            if (xmin == 0 && ymin == 0) {
                diff = integral_image[ymax][xmax];
                sqdiff = integral_sqimage[ymax][xmax];
            } else if (xmin == 0 && ymin > 0) {
                diff = integral_image[ymax][xmax] - integral_image[ymin - 1][xmax];
                sqdiff = integral_sqimage[ymax][xmax] - integral_sqimage[ymin - 1][xmax];
            } else if (xmin > 0 && ymin == 0) {
                diff = integral_image[ymax][xmax] - integral_image[ymax][xmin - 1];
                sqdiff = integral_sqimage[ymax][xmax] - integral_sqimage[ymax][xmin - 1];
            } else {
                // rest of the image
                diagsum = integral_image[ymax][xmax] + integral_image[ymin - 1][xmin - 1];
                idiagsum = integral_image[ymin - 1][xmax] + integral_image[ymax][xmin - 1];
                //以(i,j)为中心点的w邻域内灰度值的积分
                diff = diagsum - idiagsum;

                sqdiagsum = integral_sqimage[ymax][xmax] + integral_sqimage[ymin - 1][xmin - 1];
                sqidiagsum = integral_sqimage[ymax][xmin - 1] + integral_sqimage[ymin - 1][xmax];
                //以(i,j)为中心点的w邻域内灰度值平方的积分
                sqdiff = sqdiagsum - sqidiagsum;
            }
            mean = diff / area;
            //以(i,j)为中心点的w邻域内的标准方差
            std = sqrt((sqdiff - diff * diff / area) / (area - 1));
            //根据Sauvola计算公式和以(i,j)为中心点的w邻域内的灰度均值与标准方差来计算当前点(i,j)的二值化阈值
            threshold = mean * (1 + k * ((std / 128) - 1));
            //根据当前点的阈值对当前像素点进行二值化
            if (GrayImage[i][j] < threshold)
                Pixle[i][j] = 0;
            else
                Pixle[i][j] = 255;
        }
    }
}
