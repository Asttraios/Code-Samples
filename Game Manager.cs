using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{
    
    GameObject player;
    SFXManager sfxManager;
    SoundManager soundManager;
    [SerializeField] private float gameOverScreenDuration;
    [SerializeField] private float gameVictoryScreenDuration;
    private bool wasPlayed;

    void Start()
    {
        player = GameObject.FindGameObjectWithTag("Player");
        sfxManager = GameObject.FindGameObjectWithTag("SFXController").GetComponent<SFXManager>();
        soundManager = GameObject.FindGameObjectWithTag("SoundController").GetComponent<SoundManager>();
        wasPlayed = false;
    }

    public void RestartLevel()
    {
        SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex);
    }

    public void LoadNewLevel()
    {
        if(SceneManager.sceneCountInBuildSettings > SceneManager.GetActiveScene().buildIndex +1)
        {
            SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex + 1);
        }
        else
        {
            SceneManager.LoadScene(0);
        }

    }

    public void GameOverSequence()
    {
        if(wasPlayed == false)
        {
        player.GetComponent<PlayerControls>().enabled = false;
        player.GetComponent<Rigidbody>().angularDrag = 0f;
        player.GetComponent<Rigidbody>().constraints &= ~RigidbodyConstraints.FreezeRotationX;
        player.GetComponent<Rigidbody>().constraints &= ~RigidbodyConstraints.FreezeRotationY;
        
        sfxManager.ExplosionSFX();
        soundManager.PlayerExplosionSounds();
       
        Invoke("RestartLevel", gameOverScreenDuration);
        }
        wasPlayed = true;
        
    }

    public void VictorySequence()
    {

        if(wasPlayed == false)
        {
        player.GetComponent <PlayerControls>().enabled = false;
        soundManager.PlayerFinishLevel();
        Invoke("LoadNewLevel", gameVictoryScreenDuration);
        }
        wasPlayed = true;

    }

    //total destruction sequence after hitting ground
}
