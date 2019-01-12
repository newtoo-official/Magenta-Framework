/*
 * Copyright (C) 2018 Dmitry Kozichev. All rights reserved.
 *
 * MFAnimation.h
 * Created on 12 џэт. 2019 у.
 */

#pragma once

#include "../MagentaFrameworkFlags.h"

typedef double MFASeconds;
class MFAnimation;
class MFAKeyframe;

#include <vector>
class MFAKeyframeSet
{
	MFAnimation *m_animation;
	std::vector<MFAKeyframe*> m_sequence;
	bool m_weak;
public:
	MFAKeyframeSet(MFAnimation*);

	MFAKeyframe *operator[](std::size_t);
	void removeKeyframe(std::size_t);
	void appendKeyframe(MFAKeyframe*);

	std::vector<MFAKeyframe*>::iterator begin();
	std::vector<MFAKeyframe*>::iterator end();
	std::size_t size();

	MFAnimation *getAnimation() const;

	/* weak frame set */
	MFAKeyframeSet(MFAnimation*, MFASeconds at);

	~MFAKeyframeSet();
};

class MFAnimation
{
public:
	MFAnimation(MFASeconds duration = 0.0f);

	enum
	AnimationDirection {
		Forward,
		ForwardReverse,
		Backward,
		BackwardReverse,
	};

	enum
	AnimationCircleState {
		Working,
		PendingToTerminate,
		Terminated
	};

protected:
	bool m_playing = false;

	AnimationCircleState m_state = Working;

	MFASeconds m_duration, m_position = 0;
	AnimationDirection m_direction = Forward;
	double m_speed = 1.0f;
	bool m_repeat = false;

	MFAKeyframeSet m_keyframes;

public:
	void playFrame();

	void appendKeyframe(MFAKeyframe*);

	bool isPlaying() const;

	MFASeconds getDuration() const;
	void setDuration(MFASeconds);

	MFASeconds getPosition() const;
	void setPosition(MFASeconds);

	AnimationDirection getDirection() const;
	void setDirection(AnimationDirection);

	double getSpeed() const;
	void setSpeed(double);

	bool isRepeat() const;
	void setRepeat(bool);

	MFAKeyframeSet& keyframes();

	void rewindToBeginning();
	void rewindToStart();
	void rewindToEnd();

	void play();
	void pause();
	void stop();

	virtual ~MFAnimation();
};


