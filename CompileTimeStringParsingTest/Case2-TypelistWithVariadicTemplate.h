#pragma once

struct null_type {};

template <typename Head, typename Tail>
struct typenode
{
	typedef Head head_type;
	typedef Tail tail_type;
};

template <typename... T>
struct typelist;

template <>
struct typelist<>
{
	typedef null_type type;
};

template <typename Head, typename... Rest>
struct typelist<Head, Rest...>
{
	typedef typenode<Head, typename typelist<Rest...>::type> type;
};

void case2();