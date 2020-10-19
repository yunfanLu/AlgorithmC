//
// Created by YunfanLu on 2020/2/15.
//

#ifndef  ALGORITHM_BIT_H_
#define  ALGORITHM_BIT_H_

/* 获取缓存 bits 中位置处于 pos 的状态。缓存区最左侧的位置是 0。返回的状态是 0 或者 1。*/
int bit_get(const unsigned char *bits,
            int                  pos);

/* 设置缓存 bits 中位置处于 pos 的状态为 state。 state 的值必须是 0 或者 1。*/
void bit_set(unsigned char *bits,
             int            pos,
             int            state);

/* 按位计算两个缓冲区的异或值，这两个缓存区的长度为 size，将其结果放在 bitsx 中。 */
void bit_xor(const unsigned char *bits1,
             const unsigned char *bits2,
             unsigned char       *bitsx,
             int                  size);

/* 循环左移，缓冲区的长度是 size，移动 count 位。 */
void bit_rot_left(unsigned char *bits,
                  int            size,
                  int            count);


#endif // ALGORITHM_BIT_H_
