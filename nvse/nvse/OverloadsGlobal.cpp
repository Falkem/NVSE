#include "Utilities.h"

#if !_DEBUG

void* operator new(size_t size)
{
	auto* allocation = GameHeapAlloc(size);
	if (allocation == nullptr)
	{
		throw std::bad_alloc();
	}
	return allocation;
}

void operator delete(void* address)
{
	GameHeapFree(address);
}

void* operator new[](size_t size)
{
	auto* allocation = GameHeapAlloc(size);
	if (allocation == nullptr)
	{
		throw std::bad_alloc();
	}
	return allocation;
}

void operator delete[](void* address)
{
	GameHeapFree(address);
}

#endif