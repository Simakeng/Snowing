#pragma once
#include "AudioChannel.h"
#include <Snowing.h>
#include <future>

namespace Yukimi
{
	class[[nodiscard]] BGMPlayer final : 
		public Snowing::SingleInstance<BGMPlayer>,
		private virtual Snowing::Scene::Group<AudioChannel>,
		public virtual Snowing::Scene::Object
	{
	private:
		// ��Ӧ��ֱ��ͨ��ָ����ʶ��󣬽����ڴ�Group���ж�ĳ�������Ƿ�Ϊ��ǰ�Ĳ��Ŷ���
		AudioChannel* currentChannel_ = nullptr;

		const AudioChannel::AudioLoader loader_;

		void stopAllChannels(float fadeTime);
	public:

		BGMPlayer(AudioChannel::AudioLoader loader);

		// ����BGM
		void Play(Snowing::AssetName, float fadeTime = 0, uint32_t begin = 0);

		// ֹͣBGM
		void Stop(float fadeTime = 0);

		// �ӵ�ǰ����λ�ã����������л�������һ��BGM
		void FadeTo(Snowing::AssetName, float fadeTime = 0);

		// ��ͣ
		void Pause(float fadeTime = 0);

		// ����ͣ�лָ�
		void Resume(float fadeTime = 0);

		bool Update() override;
	};
}