// Copyright 2012 Google Inc. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef BT_FAN_OUT_GESTURE
#define BT_FAN_OUT_GESTURE

#include "BT_Gesture.h"

class Pile;

class FanOutGesture : public Gesture
{
private:
	// Maximum change in separation between two fingers are moving to be considered a swipe; different from Gesture::isTwoFingerSwipe 
	static const float MAXIMUM_SEPARATION_CHANGE;
	static const float MINIMUM_PATH_LENGTH; // Minimum distance moved by two fingers in order to recognize gesture
	Pile * _pile; // Selected pile for fan out
	Vec3 _lastPoint; // Used for fan out path

protected:
	virtual void clearGesture();
	virtual Detected isRecognizedImpl(GestureContext *gestureContext);
	virtual bool processGestureImpl(GestureContext *gestureContext);

public:
	FanOutGesture();
};

#endif