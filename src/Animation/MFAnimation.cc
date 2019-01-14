/*
 * Copyright (C) 2019 Dmitry Kozichev. All rights reserved.
 *
 * MFAnimation.cc
 * Created on 12.01.2019
 */

#include "MFAnimation.h"
#include "MFAKeyframe.h"
#include "MFAnimationCycle.h"

MFAKeyframeSet::MFAKeyframeSet(MFAnimation *animation)
: m_animation(animation), m_weak(false)
{
}

MFAKeyframe* MFAKeyframeSet::operator[](std::size_t index)
{
	return m_sequence[index];
}

void MFAKeyframeSet::removeKeyframe(std::size_t index)
{
	m_sequence.erase(index + m_sequence.begin());
}

void MFAKeyframeSet::appendKeyframe(MFAKeyframe* frame)
{
	frame->setFoundation(m_animation);
	m_sequence.emplace_back(frame);
}

std::vector<MFAKeyframe*>::iterator MFAKeyframeSet::begin()
{
	return m_sequence.begin();
}
std::vector<MFAKeyframe*>::iterator MFAKeyframeSet::end()
{
	return m_sequence.end();
}
std::size_t MFAKeyframeSet::size()
{
	return m_sequence.size();
}

MFAnimation* MFAKeyframeSet::getAnimation() const
{
	return m_animation;
}

MFAKeyframeSet::MFAKeyframeSet(MFAnimation *animation, MFASeconds at)
: m_animation(animation), m_weak(true)
{
	//TODO: Make filter
}

MFAKeyframeSet::~MFAKeyframeSet()
{
	if(!m_weak)
	{
		for(MFAKeyframe *each : m_sequence)
			delete each;
	}
}

MFAnimation::MFAnimation(MFASeconds duration) : m_duration(duration), m_keyframes(this)
{
	MFAnimationCycle* cycle = new MFAnimationCycle(this);
	cycle->run();
}

void MFAnimation::playFrame()
{
	if (!m_playing)
		return;

	if (m_direction == AnimationDirection::Forward
	 || m_direction == AnimationDirection::ForwardReverse)
	{
		m_position += 0.01 * m_speed;
		if (m_position > m_duration)
		{
			if (m_repeat)
			{
				m_direction == AnimationDirection::ForwardReverse?
					setDirection(AnimationDirection::BackwardReverse):
					rewindToStart();
			}
			else stop();
		}
	} else
	{
		m_position -= 0.01 * m_speed;
		if (m_position < 0)
		{
			if (m_repeat)
			{
				m_direction == AnimationDirection::BackwardReverse?
					setDirection(AnimationDirection::ForwardReverse):
					rewindToEnd();
			}
			else stop();
		}
	}
	for(MFAKeyframe *keyframe : m_keyframes)
		keyframe->play();
}

void MFAnimation::appendKeyframe(MFAKeyframe *frame)
{
	keyframes().appendKeyframe(frame);
}

bool MFAnimation::isPlaying() const
{
	return m_playing;
}

MFASeconds MFAnimation::getDuration() const
{
	return m_duration;
}
void MFAnimation::setDuration(MFASeconds duration)
{
	m_duration = duration;
}

MFASeconds MFAnimation::getPosition() const
{
	return m_position;
}
void MFAnimation::setPosition(MFASeconds position)
{
	m_position = position;
}

MFAnimation::AnimationDirection MFAnimation::getDirection() const
{
	return m_direction;
}
void MFAnimation::setDirection(AnimationDirection direction)
{
	m_direction = direction;
}

MFAnimation::AnimationCycleState MFAnimation::getCycleState() const
{
	return m_state;
}

void MFAnimation::setCycleState(AnimationCycleState state)
{
	m_state = state;
}

double MFAnimation::getSpeed() const
{
	return m_speed;
}
void MFAnimation::setSpeed(double speed)
{
	m_speed = speed;
}

bool MFAnimation::isRepeat() const
{
	return m_repeat;
}
void MFAnimation::setRepeat(bool repeat)
{
	m_repeat = repeat;
}

MFAKeyframeSet& MFAnimation::keyframes()
{
	return m_keyframes;
}

void MFAnimation::rewindToBeginning()
{
	m_direction == AnimationDirection::Forward ||
	m_direction == AnimationDirection::ForwardReverse?
    rewindToStart() : rewindToEnd();
}
void MFAnimation::rewindToStart()
{
	m_position = 0;
}
void MFAnimation::rewindToEnd()
{
	m_position = m_duration;
}

void MFAnimation::play()
{
	m_playing = true;
}
void MFAnimation::pause()
{
	m_playing = false;
}
void MFAnimation::stop()
{
	pause();
	rewindToBeginning();
}

MFAnimation::~MFAnimation()
{
	m_state = AnimationCycleState::PendingToTerminate;
	/*
	while(m_state != AnimationCircleState::Terminated)
	{
	}
	*/
}
