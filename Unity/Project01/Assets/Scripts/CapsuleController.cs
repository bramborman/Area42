using UnityEngine;

namespace Project01
{
    public sealed class CapsuleController : MonoBehaviour
    {
        [SerializeField] private CharacterController characterController;
        [SerializeField] private float speedMultiplier;

        private void Update()
        {
            float x = Input.GetAxis("Horizontal");
            float z = Input.GetAxis("Vertical");

            characterController.Move(new Vector3(x, 0f, z) * speedMultiplier * Time.deltaTime);

            ////Vector3 position = transform.position;
            ////position.x += x * speedMultiplier * Time.deltaTime;
            ////position.z += z * speedMultiplier * Time.deltaTime;

            ////transform.position = position;
        }
    }
}
