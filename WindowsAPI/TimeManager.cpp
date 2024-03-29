#include "pch.h"
#include "TimeManager.h"

void TimeManager::Init()
{
	::QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&_frequency));
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&_prevCount));
}

void TimeManager::Update()
{
	uint64 curCount;
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&curCount));

	_deltaTime = (curCount - _prevCount) / static_cast<float>(_frequency);
	_prevCount = curCount;

	_frameCount++;
	_frameTime += _deltaTime;

	if (_frameTime >= 1.0f)
	{
		_fps = static_cast<uint32>(_frameCount / _frameTime);

		_frameCount = 0;
		_frameTime = 0.0f;
	}
}
