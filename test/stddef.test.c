#include "gtest/gtest.h"
#include "stddef.h"

typedef struct {
    int a;
    int p;
} sct;

TEST(offsetof, POSITIVE)
{
    EXPECT_EQ(4, offsetof(sct, p));
}
TEST(container_of, POSITIVE)
{
    sct t;
    int *p = &(t.p);
    EXPECT_EQ(container_of(p, sct, p) + offsetof(sct, p), p);
}
