#pragma once

struct null_type {};

/// <summary>
/// typelist
/// </summary>
/// <typeparam name="Head"></typeparam>
/// <typeparam name="Tail"></typeparam>

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

/// <summary>
/// Length of typelist
/// </summary>
/// <typeparam name="TL"></typeparam>

template <typename TL>
struct length
{
	static const int value = 1 + length<typename TL::tail_type>::value;
};

template<>
struct length<null_type>
{
	static const int value = 0;
};

/// <summary>
/// TypeAt of typelist
/// </summary>
/// <typeparam name="TL"></typeparam>

template <typename TL, int index>
struct type_at
{
	typedef typename type_at<typename TL::tail_type, index - 1>::type type;
};

template <typename Head, typename Tail>
struct type_at<typenode<Head, Tail>, 0>
{
	typedef Head type;
};

/// <summary>
/// visitor of typelist
/// </summary>
/// <typeparam name="TL"></typeparam>

template <typename TL, template <class> class Delegator>
struct visitor
{
	static void execute()
	{
		Delegator<typename TL::head_type>::execute();
		visitor<typename TL::tail_type, Delegator>::execute();
	}
};

template <template <class> class Delegator>
struct visitor<null_type, Delegator>
{
	static void execute() {}
};

void case2();