using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UIElements;

public class NewFreeCamera : MonoBehaviour
{
    [SerializeField] private float normalSpeed;
    [SerializeField] private float sprintSpeed;
    [SerializeField] private float mouseSens;
    private float mouseX;
    private float mouseY;
    private Vector3 moveDirection;
    private Vector3 rotationVector;

    
    void Start()
    {
       
    }

    // Update is called once per frame
    void Update()
    {


        moveDirection.x = Input.GetAxis("Horizontal");
        moveDirection.z = Input.GetAxis("Vertical");
        moveDirection.y = Input.GetAxis("UpDown");

        mouseY += Input.GetAxis("Mouse X")*mouseSens;
        mouseX -= Input.GetAxis("Mouse Y")*mouseSens;

        moveDirection *= normalSpeed;


        if(Input.GetKey(KeyCode.LeftShift))
        {
            moveDirection *= sprintSpeed;
        }

        mouseX = Mathf.Clamp(mouseX, -90, 90);
        
        transform.Translate(moveDirection.x, 0, moveDirection.z, Space.Self);
        transform.Translate(0, moveDirection.y, 0, Space.World);
        
        transform.rotation = Quaternion.Euler(mouseX, mouseY, 0);

        
    }
}
