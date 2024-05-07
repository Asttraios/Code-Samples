using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class CollisionControl : MonoBehaviour
{
    GameManager gameManager;
    SoundManager soundManager;

    void Start()
    {
        gameManager = GameObject.FindGameObjectWithTag("GameController").GetComponent<GameManager>();
        //soundManager = GameObject.FindGameObjectWithTag("SoundController").GetComponent <SoundManager>();
        
    }

    private void OnCollisionEnter(Collision obstacle)
    {


        switch (obstacle.gameObject.tag)
        {
            case "Respawn":
                {
                    Debug.Log("Ready to start");
                }
                break;

            case "Obstacle":
                {
                    Debug.Log("you lost");
                    //soundManager.PlayerExplosionSounds();
                    gameManager.GameOverSequence();
                    
                }
                break;

            case "Finish":
                {
                    Debug.Log("koniec");
                    //soundManager.PlayerFinishLevel();
                    gameManager.VictorySequence();
                }
                break;


            default:
                {
                    Debug.Log("Undefined object hit");
                }
                break;
        }
    }

    
}
