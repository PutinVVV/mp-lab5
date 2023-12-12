#include "TQueue.h"
#include <gtest.h>

TEST(TQueue, can_create_queue_with_positive_length)
{
	ASSERT_NO_THROW(TQueue<int> q(5));
}

TEST(TQueue, cant_create_too_large_queue)
{
	ASSERT_NO_THROW(TQueue<int> q(0));
}

TEST(TQueue, throws_when_create_queue_with_negative_length)
{
	ASSERT_ANY_THROW(TQueue<int> q(-5));
}

TEST(TQueue, can_create_copied_queue)
{
	TQueue<int> s1(10);
	ASSERT_NO_THROW(TQueue<int> q2(s1));
}

TEST(TQueue, knows_if_empty1)
{
	TQueue<int> q(5);
	EXPECT_EQ(true, q.IsEmpty());
}

TEST(TQueue, knows_if_empty2)
{
	TQueue<int> q(5);
	EXPECT_EQ(true, q.IsEmpty());
	q.Push(11);
	EXPECT_EQ(false, q.IsEmpty());
}

TEST(TQueue, knows_if_empty3)
{
	TQueue<int> q(5);
	EXPECT_EQ(true, q.IsEmpty());
	q.Push(11);
	EXPECT_EQ(false, q.IsEmpty());
	q.TopPop();
	EXPECT_EQ(true, q.IsEmpty());
}

TEST(TQueue, can_assign_queue_to_itself)
{
	TQueue<int> q(5);
	ASSERT_NO_THROW(q = q);
}