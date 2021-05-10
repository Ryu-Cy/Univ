using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ButtonScript : MonoBehaviour
{
    bool bCheck_Parameter = true;

    int bHardWare = 0;

    [SerializeField] private InputField Name_Input;
    [SerializeField] private InputField PassWord_Input;

    [SerializeField] private Slider Slider_Value;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void MyButtonClick()
    {
        Debug.Log("Button Click");
    }
    public void MyCheckBoxClick()
    {
        bCheck_Parameter = !bCheck_Parameter;
        Debug.Log("Check: " + bCheck_Parameter);
    }
    public void MyDxRadioButtonClick()
    {
        bHardWare = 1;
        Debug.Log("Select: Dx" + bHardWare);
    }
    public void MyGLRadioButtonClick()
    {
        bHardWare = 2;
        Debug.Log("Select: OpenGL" + bHardWare);
    }
    public void MyInputField_Name()
    {
        if (Name_Input.text == "Ryu")
            Debug.Log("Ok");
    }
    public void MyInputField_PassWord()
    {
        if (PassWord_Input.text == "1576")
            Debug.Log("Ok");
    }
    public void MySlider()
    {
        Debug.Log("Slider Value: " + Slider_Value.value);
    }
}
