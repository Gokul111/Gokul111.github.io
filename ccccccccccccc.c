#include <cstdlib>
002
#include <iostream>
003
#include <stack>
004
using namespace std;
005
 
006
#define ARRAY_SIZE 20
007
 
008
//  Prototype Declarations
009
void fillArray(int numArray[]);
010
void quickSortNR(int data[]);
011
void medianToLeft(int data[], int left,  int right);
012
void sortSide(int data[], int &start, const int end);
013
 
014
int main (void)
015
{
016
//  Local Declarations
017
    int i;
018
    int ary[ARRAY_SIZE];
019
 
020
//  Statements
021
 
022
    fillArray(ary);
023
 
024
    quickSortNR(ary);
025
 
026
    return 0;
027
}   // main
028
 
029
void fillArray(int numArray[])
030
{
031
    for(int x = 0; x < ARRAY_SIZE; x++)
032
    {
033
        numArray[x] = rand() % 49 + 1;
034
    }
035
} // end fillArray
036
 
037
/*  =============== medianToLeft ================
038
    Find the median value of an array, data[left..right],
039
    and place it in the location data[left].
040
       Pre  data is an array of at least three elements
041
             left and right are the boundaries of the array
042
       Post  median value placed at data[left]
043
*/
044
void medianToLeft (int data[],
045
                 int left,
046
                 int right)
047
{
048
//  Local Definitions
049
    int mid;
050
    int hold;
051
 
052
//  Statements
053
    //  Rearrange sortData so median is in middle location 
054
    mid = (left + right) / 2;
055
    if (data[left] > data[mid])
056
       {
057
        hold = data[left];
058
        data[left] = data[mid];
059
        data[mid] = hold;
060
       } // if
061
    if (data[left] > data[right])
062
       {
063
        hold = data[left];
064
        data[left] = data[right];
065
        data[right] = hold;
066
       } // if
067
    if (data[mid] > data[right])
068
       {
069
        hold = data[mid];
070
        data[mid] = data[right];
071
        data[right] = hold;
072
       } // if
073
    // Median is in middle. Exchange with left.
074
    hold = data[left];
075
    data[left] = data[mid];
076
    data[mid] = hold;
077
 
078
    return;
079
}   // medianToLeft
080
 
081
/*  ================ quickSortNR =================
082
    Array data[] is sorted without recursion.
083
       @pre   data is an array of data to be sorted
084
       @post  data array is sorted
085
*/
086
void quickSortNR  (int data[])
087
{
088
//  Local Definitions
089
    int sorted = 0;     // keeps track of the number of sorted items
090
                        // and also determines start for next sort.
091
    int rightStart = ARRAY_SIZE;    // Starting point of the
092
                                    // right partition
093
                 
094
    medianToLeft(data, sorted, rightStart);
095
    sortSide(data, sorted, rightStart); // split to left and right
096
     
097
    while(sorted <= rightStart)
098
    {
099
        medianToLeft(data, sorted, rightStart);
100
        sortSide(data, sorted, rightStart); // sort left side
101
    }
102
    while(sorted < ARRAY_SIZE)
103
    {
104
        medianToLeft(data, sorted, ARRAY_SIZE);
105
        sortSide(data, sorted, ARRAY_SIZE); // sort right side
106
    } // end while
107
} // end quickSortNR
108
 
109
/* ========== sortSide ================
110
    This function will 'partition' the array using a stack. 
111
    If either partition has 3 or less items, then those are
112
    automatically sorted.
113
    @pre    There are items in the array
114
    @post   Items in the array are placed in order of
115
            < pivot; pivot; > pivot               */
116
void sortSide(int data[], int &start, int end)
117
{
118
    // Local Declarations
119
    int pivotVal = data[start-1];   // temporary variable to
120
                                    // hold the value of the pivot 
121
    stack<int> lStack;
122
    stack<int> rStack;
123
    int stSize = 0; // # of items in stack
124
    int cur = start + 1;
125
    int temp;
126
     
127
    // Statements
128
    while(cur < end) // traverse through the items
129
                        // in the array (skip pivot)
130
    {
131
        // separate items into left and right stacks
132
        if(data[cur] < pivotVal)
133
            lStack.push(data[cur]);
134
        else
135
            rStack.push(data[cur]);
136
 
137
        cur++;
138
    } // end while
139
    cur = start;    // reset cur variable
140
    stSize = lStack.size(); // get size of stack before
141
                            // moving back to array.
142
    while (!lStack.empty())
143
    {
144
        data[cur] = lStack.top();
145
        lStack.pop();
146
        cur++;
147
    }
148
 
149
    /*  If there are 3 or less items in the stack,
150
        sort them without using another stack   */
151
    switch(stSize)
152
        {
153
        case 3:
154
            start+= 4;  //items in left stack
155
                        //and pivot are sorted.
156
            if(data[cur] > data[cur+1])
157
            {
158
                int temp = data[cur];
159
                data[cur] = data[cur+1];
160
                data[cur+1] = temp;
161
            }
162
            if(data[cur] > data[cur+1])
163
            {
164
                temp = data[cur];
165
                data[cur] = data[cur+1];
166
                data[cur+1] = temp;
167
            }
168
            if(data[cur+1] > data[cur+2])
169
            {
170
                temp = data[cur+1];
171
                data[cur+1] = data[cur+2];
172
                data[cur+2] = temp;
173
            }
174
            break;
175
        case 2:
176
            start += 3;
177
            if(data[cur] > data[cur+1])
178
            {
179
                int temp = data[cur];
180
                data[cur] = data[cur+1];
181
                data[cur+1] = temp;
182
            }
183
            break;
184
        case 1:
185
            start += 2;
186
            break;
187
        case 0:
188
            start++;
189
            break;
190
    } // end switch
191
 
192
    data[cur] = pivotVal;
193
    start++;
194
    cur++;     
195
 
196
    // SORT THE RIGHT SIDE
197
    stSize = rStack.size(); // get size of stack before
198
                            // moving back to array.
199
    while (!rStack.empty())
200
    {
201
        data[cur] = rStack.top();
202
        rStack.pop();
203
        cur++;
204
    }
205
 
206
    /*  If there are 3 or less items in the stack,
207
        sort them without using another stack   */
208
    switch(stSize)
209
        {
210
        case 3:
211
            start+= 4;  //items in left stack
212
                        //and pivot are sorted.
213
            if(data[cur] > data[cur+1])
214
            {
215
                int temp = data[cur];
216
                data[cur] = data[cur+1];
217
                data[cur+1] = temp;
218
            }
219
            if(data[cur] > data[cur+1])
220
            {
221
                temp = data[cur];
222
                data[cur] = data[cur+1];
223
                data[cur+1] = temp;
224
            }
225
            if(data[cur+1] > data[cur+2])
226
            {
227
                temp = data[cur+1];
228
                data[cur+1] = data[cur+2];
229
                data[cur+2] = temp;
230
            }
231
            break;
232
        case 2:
233
            start += 3;
234
            if(data[cur] > data[cur+1])
235
            {
236
                int temp = data[cur];
237
                data[cur] = data[cur+1];
238
                data[cur+1] = temp;
239
            }
240
            break;
241
        case 1:
242
            start += 2;
243
            break;
244
        case 0:
245
            start++;
246
            break;
247
    } // end switch
248
 
249
    data[cur] = pivotVal;
250
    start++;
251
    cur++;     
252
} // end sortSide
