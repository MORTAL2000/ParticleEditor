#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <Thor/Particles.hpp>

namespace px
{
	class Application
	{
	public:
		Application();
		~Application();

	public:
		void run();

	private:
		void pollEvents();
		void update(sf::Time dt);
		void updateParticles(sf::Time dt);
		void updateGUI();
		void render();
		void openFile(std::string & filePath, std::string & file);

	private:
		struct Properties
		{
			bool looping = true;
			float radius = 1.f;
			float nrOfParticles = 1.f;
			sf::Vector2f rotationSpeed = sf::Vector2f(0.f, 0.f);
			sf::Vector2f rotation = sf::Vector2f(0.f, 0.f);
			sf::Vector2f lifetime = sf::Vector2f(1.f, 1.f);
			sf::Vector2f halfSize = sf::Vector2f(1.f, 1.f);
			sf::Vector2f position = sf::Vector2f(400.f, 400.f);
			sf::Vector2f scale = sf::Vector2f(0.05f, 0.05f);
			sf::Vector2f velocity = sf::Vector2f(0.f, 0.f);
			sf::Vector2f fader = sf::Vector2f(0.f, 0.f);
			sf::Color color = sf::Color::White;
		};

	private:
		sf::RenderWindow m_window;
		std::string m_shape, m_fullParticlePath, m_particlePath;
		sf::Texture m_particleTexture;
		sf::Sprite m_textureButton;
		sf::BlendMode m_blendMode;
		thor::ParticleSystem m_particleSystem;
		thor::UniversalEmitter m_emitter;
		thor::Connection m_emitterConnection;
		Properties m_particle;
	};
}