#pragma once

#include <msclr/lock.h>

using namespace System;
using namespace System::Threading;
using namespace System::Runtime::Remoting;
using namespace Aemulus::Tech::Flow;
using namespace Aemulus::Tech::Flow::ProductionSystem;

namespace Aemulus { namespace Tech {

	public ref class CountdownEvent
	{
	private:
		Object^ _lock;
		int _initialCount;
		array<bool>^ _flags;
		Action<CountdownEvent^>^ _action;

		void Init(int initialCount, Action<CountdownEvent^>^ postPhaseAction)
		{
			_lock = gcnew Object();
			_initialCount = initialCount;
			_action = postPhaseAction;
			_flags = gcnew array<bool>(_initialCount);
		}

		bool IsAllPresent()
		{
			bool all = true;
			for each(bool f in _flags) {
				if(!f) {
					all = false;
					break;
				}
			}
			return all;
		}

	public:
		CountdownEvent(int initialCount)
		{
			Init(initialCount, nullptr);
		}

		CountdownEvent(int initialCount, Action<CountdownEvent^>^ postPhaseAction)
		{
			Init(initialCount, postPhaseAction);
		}

		void Reset(array<bool>^ flags)
		{
			msclr::lock enter(_lock);
			for(int i=0; i<_flags->Length; i++)
				_flags[i] = flags[i];
		}

		void Reset()
		{
			msclr::lock enter(_lock);
			for(int i=0; i<_flags->Length; i++)
				_flags[i] = false;
		}

		void Signal(int index)
		{
			msclr::lock enter(_lock);
			_flags[index] = true;

			if(IsAllPresent()) {
				if(_action != nullptr)
					_action(this);
				Monitor::PulseAll(_lock);
			}
		}

		void Wait()
		{
			msclr::lock enter(_lock);

			while(!IsAllPresent())
				//Monitor::Wait(_lock, 1000, false); //sk@20150806
				Monitor::Wait(_lock, false);
		}

		~CountdownEvent()
		{
			_action = nullptr;
			_lock = nullptr;
		}
	};

}}