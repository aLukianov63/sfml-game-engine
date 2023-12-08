
#ifndef GAMETEST_SRC_ENGINE_ANIMATEDSPRITE_H_
#define GAMETEST_SRC_ENGINE_ANIMATEDSPRITE_H_

#include <functional>

#include "Animation.h"

class Animation;
class AnimatedSprite : public sf::Sprite
{
 public:
	AnimatedSprite(const AnimatedSprite&) = default;
	AnimatedSprite& operator=(const AnimatedSprite&) = default;

	AnimatedSprite(AnimatedSprite&&) = default;
	AnimatedSprite& operator=(AnimatedSprite&&) = default;

	using FuncType = std::function<void()>;
	static FuncType defaultFunc;

	enum Status
	{
		Stopped,
		Paused,
		Playing
	};

	AnimatedSprite(Animation* animation = nullptr,Status status= Playing,const sf::Time& deltaTime = sf::seconds(0.15),bool loop = true,int repeat=0);

	void setAnimation(Animation* animation);
	Animation* getAnimation()const;

	void setFrameTime(sf::Time deltaTime);
	sf::Time getFrameTime()const;

	void setLoop(bool loop);
	bool getLoop()const;

	void setRepeat(int nb);
	int getRepeat()const;

	void play();
	void pause();
	void stop();

	FuncType on_finished;

	Status getStatus()const;

	void setFrame(size_t index);

	void update(const sf::Time& deltaTime);

 private:
	Animation* _animation;
	sf::Time _delta;
	sf::Time _elapsed;
	bool _loop;
	int _repeat;
	Status _status;
	size_t _currentFrame;

	void setFrame(size_t index,bool resetTime);
};

#endif //GAMETEST_SRC_ENGINE_ANIMATEDSPRITE_H_
