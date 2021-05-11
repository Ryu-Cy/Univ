using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    public float moveSpeed = 3.0f;
    float camTime;

    public GameObject a;
    public GameObject b;
    public GameObject c;
    public GameObject d;
    public GameObject e;

    public GameObject last;

    public GameObject cam1;
    public GameObject cam2;
    public GameObject cam3;
    public GameObject cam4;

    // Start is called before the first frame update
    void Start()
    {
        camTime = 3.0f;
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey(KeyCode.LeftArrow))
        {
            transform.Translate(Vector3.left * moveSpeed * Time.deltaTime);
        }
        if (Input.GetKey(KeyCode.RightArrow))
        {
            transform.Translate(Vector3.right * moveSpeed * Time.deltaTime);
        }
        if (Input.GetKey(KeyCode.UpArrow))
        {
            transform.Translate(Vector3.forward * moveSpeed * Time.deltaTime);
        }
        if (Input.GetKey(KeyCode.DownArrow))
        {
            transform.Translate(Vector3.back * moveSpeed * Time.deltaTime);
        }

        if (camTime < 0.0f)
        {
            cam1.SetActive(false);
            cam2.SetActive(false);
            cam3.SetActive(false);
        }
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.tag == "A")
        {
            cam1.SetActive(true);
            a.GetComponent<Ferris_Wheel>().enabled = true;
        }
        if (other.tag == "B")
        {
            cam2.SetActive(true);
            b.GetComponent<Pirate_Ship>().enabled = true;
        }
        if (other.tag == "C")
        {
            cam3.SetActive(true);
            c.GetComponent<Balloon>().enabled = true;
            e.SetActive(true);
        }
    }
    private void OnTriggerStay(Collider other)
    {
        if (other.tag == "A")
        {
            camTime -= Time.deltaTime;
        }
        if (other.tag == "B")
        {
            camTime -= Time.deltaTime;
        }
        if (other.tag == "C")
        {
            camTime -= Time.deltaTime;
            if (Input.GetKey(KeyCode.Space))
            {
                cam4.SetActive(true);
                last.SetActive(true);
                d.GetComponent<Hot_Air_Balloon>().enabled = true;
                Destroy(gameObject, 0);
            }
        }
    }
    private void OnTriggerExit(Collider other)
    {
        if (other.tag == "A")
        {
            camTime = 3.0f;
        }
        if (other.tag == "B")
        {
            camTime = 3.0f;
        }
        if (other.tag == "C")
        {
            camTime = 3.0f;
        }
    }
}
