using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class NewBehaviourScript : MonoBehaviour
{
    protected Animator ani;
    
    // Start is called before the first frame update
    void Start()
    {
        ani = GetComponent<Animator>();
        ani.SetFloat("Speed1", 0.0f);
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.A))
        {
            ani.SetFloat("Speed1", 1.0f);
        }
        if (Input.GetKeyDown(KeyCode.D))
        {
            ani.SetFloat("Speed1", 2.0f);
        }
        if (Input.GetKeyDown(KeyCode.W))
        {
            ani.SetFloat("Speed1", 3.0f);
        }
        if (Input.GetKeyDown(KeyCode.S))
        {
            ani.SetFloat("Speed1", 4.0f);
        }
    }
}
